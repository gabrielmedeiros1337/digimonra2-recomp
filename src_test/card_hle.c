/* SDK entry points verified against the USA DOL, not a raw EXI device. */
#include "card_hle.h"
#include "card_store.h"
#include "hle_callbacks.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
static bool s_mounted;
static int s_result=-3;
static u8 s_disk_id[6];
static bool valid(CPUState* c,u32 p,u32 n){u32 base=p&0xe0000000u,off=p&0x1fffffffu;return (base==0x80000000u||base==0xc0000000u)&&off<=c->ram_size&&n<=c->ram_size-off;}
static u8* ptr(CPUState* c,u32 p){return c->ram+(p&0x1fffffffu);}
static void be16(u8* p,u16 x){p[0]=(u8)(x>>8);p[1]=(u8)x;}
static void be32(u8* p,u32 x){p[0]=(u8)(x>>24);p[1]=(u8)(x>>16);p[2]=(u8)(x>>8);p[3]=(u8)x;}
static u16 rd16(const u8* p){return (u16)(p[0]<<8|p[1]);}
static u32 rd32(const u8* p){return (u32)p[0]<<24|(u32)p[1]<<16|(u32)p[2]<<8|p[3];}
static int channel(u32 ch,bool need_mount){return ch>1?-128:ch==1?-3:need_mount&&!s_mounted?-3:0;}
static bool name_read(CPUState* c,u32 p,char name[33]){for(u32 i=0;i<33;i++){if(!valid(c,p+i,1))return false;name[i]=(char)*ptr(c,p+i);if(!name[i])return i>0;}return false;}
static void file_info(CPUState* c,u32 p,int file){memset(ptr(c,p),0,20);mem_write32(c,p,0);mem_write32(c,p+4,(u32)file);mem_write16(c,p+16,5);}
void card_hle_reset(void){s_mounted=false;s_result=-3;memset(s_disk_id,0,6);}
static void stat_fill(u8* stat,const u8* d,u32 size){
 memset(stat,0,108);memcpy(stat,d+8,32);be32(stat+0x20,size);memcpy(stat+0x24,d+0x28,4);memcpy(stat+0x28,d,6);stat[0x2e]=d[7];memcpy(stat+0x30,d+0x2c,4);memcpy(stat+0x34,d+0x30,4);memcpy(stat+0x38,d+0x3c,4);
 u32 offset=rd32(d+0x2c);if(offset==0xffffffffu){stat[0x2e]=0;be16(stat+0x34,0);be16(stat+0x36,0);offset=0;}
 u32 banner=d[7]&3;be32(stat+0x3c,banner==1||banner==2?offset:0xffffffffu);be32(stat+0x40,banner==1?offset+0xc00:0xffffffffu);offset+=banner==1?0xe00:banner==2?0x1800:0;
 bool tlut=false;u16 icons=rd16(d+0x30);for(int i=0;i<8;i++){u32 fmt=(icons>>(2*i))&3;be32(stat+0x44+i*4,fmt==1||fmt==2?offset:0xffffffffu);if(fmt==1){offset+=0x400;tlut=true;}else if(fmt==2)offset+=0x800;}
 be32(stat+0x64,tlut?offset:0xffffffffu);if(tlut)offset+=0x200;be32(stat+0x68,offset);
}
int card_hle_dispatch(CPUState* c,u32 pc){
 u32 a=c->gpr[3],b=c->gpr[4],d=c->gpr[5],e=c->gpr[6],f=c->gpr[7];int r=0;u32 callback=0,ch=a;bool async=false;u8 dir[64];u32 size=0;char name[33];
#define ASYNC(cb) do {async=true;callback=(cb);if(callback&&!hle_callbacks_has_space()){r=-1;goto done;}if(callback&&((callback&3u)||!valid(c,callback,4))){r=-128;goto done;}}while(0)
 switch(pc){
 case 0x802A8A70u: memcpy(s_disk_id,c->ram,6);break; /* CARDInit */
 case 0x802A8B4Cu: if(a&&valid(c,a,6))memcpy(s_disk_id,ptr(c,a),6);else memcpy(s_disk_id,c->ram,6);break;
 case 0x802AA8D4u: /* CARDProbeEx */
  r=channel(a,false);if(!r){if(b&&!valid(c,b,4)||d&&!valid(c,d,4)){r=-128;break;}if(b)mem_write32(c,b,128);if(d)mem_write32(c,d,CARD_BLOCK_SIZE);}break;
 case 0x802AA89Cu:r=a==0?1:0;goto done; /* CARDProbe returns BOOL */
 case 0x802AAF98u:ASYNC(e); /* CARDMountAsync(chan,work,detach,attach) */
 case 0x802AB138u: r=channel(a,false);if(!r){r=card_store_mount();s_mounted=!r;}break;
 case 0x802ABAF4u:r=channel(a,false);if(!r){r=card_store_format();s_mounted=!r;}break;
 case 0x802AB21Cu:r=channel(a,false);if(!r)s_mounted=false;break;
 case 0x802A8D30u: r=channel(a,false);if(!r)r=s_result;goto done;
 case 0x802A9040u: r=channel(a,true);if(!r)r=s_result;goto done;
 case 0x802A8F38u:r=channel(a,true);if(!r){if(!valid(c,b,2))r=-128;else mem_write16(c,b,128);}break;
 case 0x802A8FBCu:r=channel(a,true);if(!r){if(!valid(c,b,4))r=-128;else mem_write32(c,b,CARD_BLOCK_SIZE);}break;
 case 0x802A8D60u:{r=channel(a,true);int bytes=0,files=0;if(!r)r=card_store_free(&bytes,&files);if(!r){if(!valid(c,b,4)||!valid(c,d,4))r=-128;else{mem_write32(c,b,(u32)bytes);mem_write32(c,d,(u32)files);}}break;}
 case 0x802AA6A4u:ASYNC(b);b=0;goto check_card;
 case 0x802AA114u:ASYNC(d); /* CARDCheckExAsync(chan,bytesTransferred,callback) */
 case 0x802AA728u:b=0;
 case 0x802AA6CCu:
 check_card:r=channel(a,true);if(!r&&b){if(!valid(c,b,4))r=-128;else mem_write32(c,b,0);}break;
 case 0x802ABF28u:r=channel(a,true);if(!r){if(!name_read(c,b,name)||!valid(c,d,20))r=-128;else{int id=card_store_find(s_disk_id,name);r=id<0?id:0;if(!r)file_info(c,d,id);}}break;
 case 0x802ABDC8u:r=channel(a,true);if(!r){r=card_store_get((int)b,NULL,NULL);if(!r){if(!valid(c,d,20))r=-128;else file_info(c,d,(int)b);}}break;
 case 0x802AC0A0u:if(!valid(c,a,20))r=-128;else{ch=mem_read32(c,a);r=channel(ch,true);if(!r)mem_write32(c,a,0xffffffffu);}break;
 case 0x802AC22Cu:ASYNC(f);
 case 0x802AC44Cu:r=channel(a,true);if(!r){if(!name_read(c,b,name)||!valid(c,e,20))r=-128;else{int id=card_store_create(s_disk_id,name,d);r=id<0?id:0;if(!r)file_info(c,e,id);}}break;
 case 0x802AC77Cu:case 0x802ACBB8u:ASYNC(f);
 case 0x802AC8C4u:case 0x802ACCCCu:{bool write=pc==0x802ACBB8u||pc==0x802ACCCCu;if(!valid(c,a,20)){r=-128;break;}ch=mem_read32(c,a);r=channel(ch,true);if(!r){if((write&&(d%8192||e%8192))||(!write&&(d%512||e%512))||!valid(c,b,d))r=-128;else{r=card_store_transfer((int)mem_read32(c,a+4),ptr(c,b),d,e,write);if(!r){mem_write32(c,a+8,e+d);mem_write32(c,a+12,0);}}}break;}
 case 0x802ACF2Cu:ASYNC(d);
 case 0x802AD03Cu:r=channel(a,true);if(!r){if(!name_read(c,b,name))r=-128;else{int id=card_store_find(s_disk_id,name);r=id<0?id:card_store_delete(id);}}break;
 case 0x802ACDB8u:ASYNC(d);
 case 0x802ACEE4u:r=channel(a,true);if(!r)r=card_store_delete((int)b);break;
 case 0x802AD27Cu:r=channel(a,true);if(!r){if(!valid(c,d,108))r=-128;else{r=card_store_get((int)b,dir,&size);if(!r)stat_fill(ptr(c,d),dir,size);}}break;
 case 0x802AD3A8u:ASYNC(e);
 case 0x802AD51Cu:r=channel(a,true);if(!r){if(!valid(c,d,108))r=-128;else{r=card_store_get((int)b,dir,&size);if(!r){u8* st=ptr(c,d);dir[7]=st[0x2e];memcpy(dir+0x2c,st+0x30,4);memcpy(dir+0x30,st+0x34,4);memcpy(dir+0x3c,st+0x38,4);time_t now=time(NULL);be32(dir+0x28,(u32)(now>946684800?now-946684800:0));r=card_store_set((int)b,dir);if(!r)stat_fill(st,dir,size);}}}break;
 default:return 0;
 }
 if(ch==0)s_result=r;
 if(async&&r==0&&callback){if(!hle_callbacks_enqueue(callback,ch,0)){r=-1;s_result=r;}}
#undef ASYNC
 done:c->gpr[3]=(u32)r;c->pc=c->lr;return 1;
}
