#define SDL_MAIN_HANDLED
#include "gx_gl.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s (%s)\n",__LINE__,#x,SDL_GetError());return 1;}}while(0)
static void xf_float(GXGLTransform* xf,u32 index,float value){memcpy(xf->words+index,&value,4);}
static void copy_reference(const u8* input,u8* output,u32 format,u32 step,bool luma){
    for(u32 y=0;y<24/step;y++)for(u32 x=0;x<32/step;x++){
        u32 c[4]={0};for(u32 dy=0;dy<step;dy++)for(u32 dx=0;dx<step;dx++)for(u32 k=0;k<4;k++)c[k]+=input[((y*step+dy)*32+x*step+dx)*4+k];
        for(u32 k=0;k<4;k++)c[k]/=step*step;
        u32 r=c[0],g=c[1],b=c[2],a=c[3],i=luma ? ((66*r+129*g+25*b+128)>>8)+16:r;if(i>255)i=255;
        if(format==0)r=g=b=a=(i>>4)*17;
        else if(format==1 || format==8)r=g=b=a=i;
        else if(format==2){r=g=b=(i>>4)*17;a=(a>>4)*17;}
        else if(format==3)r=g=b=i;
        else if(format==4){r=(r>>3)*255/31;g=(g>>2)*255/63;b=(b>>3)*255/31;a=255;}
        else if(format==5){if(a>=224){r=(r>>3)*255/31;g=(g>>3)*255/31;b=(b>>3)*255/31;a=255;}else{r=(r>>4)*17;g=(g>>4)*17;b=(b>>4)*17;a=(a>>5)*255/7;}}
        else if(format==7)r=g=b=a;
        else if(format==9)r=b=a=g;
        else if(format==10)r=g=a=b;
        else if(format==11){a=g;g=b=r;}
        else if(format==12){a=b;r=b=g;}
        u8* p=output+(y*(32/step)+x)*4;p[0]=(u8)r;p[1]=(u8)g;p[2]=(u8)b;p[3]=(u8)a;
    }
}
int main(void) {
    SDL_SetMainReady();CHECK(SDL_Init(SDL_INIT_VIDEO)==0);SDL_SetHint(SDL_HINT_RENDER_DRIVER,"opengl");
    SDL_Window* window=SDL_CreateWindow("GPU XF contracts",0,0,640,528,SDL_WINDOW_HIDDEN);CHECK(window);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);CHECK(renderer);
    SDL_Texture* targets[2];for(u32 i=0;i<2;i++){targets[i]=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,640,528);CHECK(targets[i]);}
    CHECK(gx_gl_xf_available(renderer));gx_gl_set_geometry_cache(true);GXGLTransform xf={0};GXGLMaterial material={0};SDL_Texture* images[8]={0};
    u8* pixels[2]={SDL_malloc(640u*528u*4u),SDL_malloc(640u*528u*4u)};CHECK(pixels[0] && pixels[1]);
    const float positions[3][3]={{-0.5f,-0.5f,-1},{0.5f,-0.5f,-1},{0,0.5f,-1}};u32 comparisons=0;
    for(u32 projection=0;projection<2;projection++)for(u32 lighting=0;lighting<2;lighting++)for(u32 scale=0;scale<2;scale++){
        memset(&xf,0,sizeof(xf));xf.projection=projection!=0;xf.lighting=lighting!=0;
        xf_float(&xf,0,1);xf_float(&xf,5,1);xf_float(&xf,10,1);
        xf_float(&xf,0x400,1);xf_float(&xf,0x404,1);xf_float(&xf,0x408,1);
        xf_float(&xf,0x101A,320);xf_float(&xf,0x101B,264);xf_float(&xf,0x101C,0);
        xf_float(&xf,0x101D,662);xf_float(&xf,0x101E,606);xf_float(&xf,0x101F,8388607.5f);
        xf_float(&xf,0x1020,1);xf_float(&xf,0x1022,1);xf_float(&xf,0x1025,-0.5f);
        xf.words[0x1026]=lighting && scale ? 1u:0u;
        xf.words[0x100A]=0x804020FFu;xf.words[0x100C]=0xFF8040FFu;xf.words[0x100E]=2;xf.words[0x1010]=2;
        GXGLVertex cpu[3]={0};GXGLRawVertex gpu[3]={0};
        for(u32 i=0;i<3;i++){
            float w=scale ? 2.0f:1.0f;memcpy(gpu[i].position,positions[i],sizeof(positions[i]));gpu[i].position[2]=-w;gpu[i].normal[2]=1;
            if(projection){float projected_w=xf.words[0x1026] ? 1.0f:w;cpu[i].x=positions[i][0]*320+320*projected_w;cpu[i].y=positions[i][1]*264+264*projected_w;cpu[i].w=projected_w;}
            else{gpu[i].position[0]=cpu[i].x=positions[i][0]*320+320;gpu[i].position[1]=cpu[i].y=positions[i][1]*264+264;cpu[i].w=1;}
            cpu[i].z=0.5f;cpu[i].clip_z=-0.5f;
            for(u32 c=0;c<4;c++){
                u8 raw=(u8)(c==0 ? 231:c==1 ? 93:c==2 ? 47:255);gpu[i].color[c]=raw;
                u32 ambient=(xf.words[0x100A]>>((3-c)*8))&255u,mat=(xf.words[0x100C]>>((3-c)*8))&255u;
                cpu[i].color[c]=lighting ? (u8)floorf((float)mat*(float)ambient/255.0f+0.5f):raw;
            }
            for(u32 j=0;j<8;j++)cpu[i].texcoord[j][2]=1;
        }
        for(u32 route=0;route<2;route++){
            CHECK(SDL_SetRenderTarget(renderer,targets[route])==0);SDL_SetRenderDrawColor(renderer,0,0,0,0);CHECK(SDL_RenderClear(renderer)==0);
            CHECK(route ? gx_gl_draw_raw(renderer,&material,images,gpu,&xf,3,0x90):gx_gl_draw(renderer,&material,images,cpu,sizeof(cpu[0]),3,0x90));
            CHECK(SDL_RenderReadPixels(renderer,NULL,SDL_PIXELFORMAT_RGBA32,pixels[route],640*4)==0);
            CHECK(pixels[route][(264u*640u+320u)*4u]>0 && pixels[route][(264u*640u+320u)*4u+3u]>0);
        }
        CHECK(gx_gl_validate_xf(renderer,&xf,gpu,cpu,sizeof(cpu[0]),3)==0);
        CHECK(!memcmp(pixels[0],pixels[1],640u*528u*4u));comparisons++;
    }
    GXGLStats before,after;gx_gl_get_stats(&before);
    GXGLVertex* stream=SDL_calloc(4096,sizeof(*stream));CHECK(stream);
    for(u32 i=0;i<4096;i++){stream[i].x=100000;stream[i].w=1;stream[i].z=0.5f;stream[i].clip_z=-0.5f;}
    for(u32 i=0;i<32;i++)CHECK(gx_gl_draw(renderer,&material,images,stream,sizeof(*stream),4096,0xB8));
    gx_gl_get_stats(&after);CHECK(after.orphans>before.orphans && after.stream_bytes-before.stream_bytes>=20u*1024u*1024u);
    CHECK(after.shader_compiles==before.shader_compiles && after.uniform_lookups==before.uniform_lookups);SDL_free(stream);
    GXGLRawVertex stable[3]={0};xf.words[0x100E]=xf.words[0x1010]=1;
    for(u32 i=0;i<3;i++){memcpy(stable[i].position,positions[i],sizeof(positions[i]));stable[i].normal[2]=1;stable[i].color[0]=123;stable[i].color[1]=55;stable[i].color[2]=99;stable[i].color[3]=255;}
    gx_gl_get_stats(&before);
    for(u32 i=0;i<3;i++)CHECK(gx_gl_draw_raw(renderer,&material,images,stable,&xf,3,0x90));
    gx_gl_get_stats(&after);CHECK(after.geometry_hits>before.geometry_hits && after.geometry_uploads>before.geometry_uploads);
    SDL_Rect center={320,264,1,1};u8 center_pixel[4];CHECK(SDL_RenderReadPixels(renderer,&center,SDL_PIXELFORMAT_RGBA32,center_pixel,4)==0 && center_pixel[0]==123);
    xf_float(&xf,3,4);SDL_SetRenderDrawColor(renderer,0,0,0,0);CHECK(SDL_RenderClear(renderer)==0);
    CHECK(gx_gl_draw_raw(renderer,&material,images,stable,&xf,3,0x90));CHECK(SDL_RenderReadPixels(renderer,&center,SDL_PIXELFORMAT_RGBA32,center_pixel,4)==0 && center_pixel[0]==0);
    xf_float(&xf,3,0);for(u32 i=0;i<3;i++)stable[i].position[0]+=4;
    CHECK(gx_gl_draw_raw(renderer,&material,images,stable,&xf,3,0x90));CHECK(SDL_RenderReadPixels(renderer,&center,SDL_PIXELFORMAT_RGBA32,center_pixel,4)==0 && center_pixel[0]==0);
    gx_gl_get_stats(&before);gx_gl_set_geometry_cache(false);
    for(u32 i=0;i<4;i++)CHECK(gx_gl_draw_raw(renderer,&material,images,stable,&xf,3,0x90));
    gx_gl_get_stats(&after);CHECK(after.geometry_hashes==before.geometry_hashes && after.dynamic_streams==before.dynamic_streams+4);
    GXGLRawVertex merged[6]={0};for(u32 i=0;i<6;i++){merged[i]=stable[i%3];memcpy(merged[i].position,positions[i%3],sizeof(positions[0]));if(i>=3)merged[i].position[0]+=0.125f;}
    for(u32 route=0;route<2;route++){
        CHECK(SDL_SetRenderTarget(renderer,targets[route])==0);SDL_SetRenderDrawColor(renderer,0,0,0,0);CHECK(SDL_RenderClear(renderer)==0);
        if(route)CHECK(gx_gl_draw_raw(renderer,&material,images,merged,&xf,6,0x90));
        else{CHECK(gx_gl_draw_raw(renderer,&material,images,merged,&xf,3,0x90));CHECK(gx_gl_draw_raw(renderer,&material,images,merged+3,&xf,3,0x90));}
        CHECK(SDL_RenderReadPixels(renderer,NULL,SDL_PIXELFORMAT_RGBA32,pixels[route],640*4)==0);
    }
    CHECK(!memcmp(pixels[0],pixels[1],640u*528u*4u));CHECK(pixels[1][(264u*640u+320u)*4u]==123);
    CHECK(SDL_SetRenderTarget(renderer,targets[0])==0);SDL_SetRenderDrawColor(renderer,17,33,65,255);CHECK(SDL_RenderClear(renderer)==0);
    SDL_Rect source={8,16,32,24},half={8,16,32,12};SDL_SetRenderDrawColor(renderer,91,123,201,247);CHECK(SDL_RenderFillRect(renderer,&half)==0);
    u8 expected_copy[32*24*4],actual_copy[32*24*4];CHECK(SDL_RenderReadPixels(renderer,&source,SDL_PIXELFORMAT_RGBA32,expected_copy,32*4)==0);
    SDL_Texture* copy=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,32,24);CHECK(copy);
    CHECK(gx_gl_copy_color(renderer,copy,&source));CHECK(SDL_SetTextureBlendMode(copy,SDL_BLENDMODE_NONE)==0);
    CHECK(SDL_SetRenderTarget(renderer,targets[1])==0);SDL_Rect destination={0,0,32,24};CHECK(SDL_RenderCopy(renderer,copy,NULL,&destination)==0);
    CHECK(SDL_RenderReadPixels(renderer,&destination,SDL_PIXELFORMAT_RGBA32,actual_copy,32*4)==0);CHECK(!memcmp(expected_copy,actual_copy,sizeof(expected_copy)));
    SDL_DestroyTexture(copy);
    u8 source_pixels[32*24*4];for(u32 y=0;y<24;y++)for(u32 x=0;x<32;x++){
        u8* p=source_pixels+(y*32+x)*4;p[0]=(u8)(x*37+y*13);p[1]=(u8)(x*7+y*19);p[2]=(u8)(x*23+y*29);p[3]=(u8)(x*17+y*31);
    }
    memset(source_pixels+sizeof(source_pixels)-4,255,4);
    SDL_Texture* input=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,32,24);CHECK(input);
    CHECK(SDL_UpdateTexture(input,NULL,source_pixels,32*4)==0);CHECK(SDL_SetTextureBlendMode(input,SDL_BLENDMODE_NONE)==0);
    CHECK(SDL_SetRenderTarget(renderer,targets[0])==0);CHECK(SDL_RenderCopy(renderer,input,NULL,&source)==0);
    CHECK(SDL_RenderReadPixels(renderer,&source,SDL_PIXELFORMAT_RGBA32,source_pixels,32*4)==0);SDL_DestroyTexture(input);
    for(u32 format=0;format<13;format++)for(u32 step=1;step<=2;step++)for(u32 luma=0;luma<2;luma++){
        u32 w=32/step,h=24/step;SDL_Texture* converted=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,(int)w,(int)h);CHECK(converted);
        CHECK(SDL_SetRenderTarget(renderer,targets[0])==0);CHECK(gx_gl_copy_texture(renderer,converted,&source,format,step,luma!=0));
        CHECK(SDL_SetRenderTarget(renderer,targets[1])==0);CHECK(SDL_SetTextureBlendMode(converted,SDL_BLENDMODE_NONE)==0);SDL_Rect to={0,0,(int)w,(int)h};CHECK(SDL_RenderCopy(renderer,converted,NULL,&to)==0);
        CHECK(SDL_RenderReadPixels(renderer,&to,SDL_PIXELFORMAT_RGBA32,actual_copy,(int)w*4)==0);copy_reference(source_pixels,expected_copy,format,step,luma!=0);
        if(memcmp(expected_copy,actual_copy,w*h*4)){for(u32 i=0;i<w*h*4;i++)if(expected_copy[i]!=actual_copy[i]){fprintf(stderr,"copy mismatch fmt=%u step=%u luma=%u byte=%u CPU=%u GPU=%u\n",format,step,luma,i,expected_copy[i],actual_copy[i]);break;}return 1;}
        SDL_DestroyTexture(converted);
    }
    printf("[GPU XF smoke] %u framebuffers, VBO wrap, and 52 exact VRAM format/filter/luma copies passed\n",comparisons);
    SDL_SetRenderTarget(renderer,NULL);gx_gl_shutdown();for(u32 i=0;i<2;i++){SDL_free(pixels[i]);SDL_DestroyTexture(targets[i]);}
    SDL_DestroyRenderer(renderer);SDL_DestroyWindow(window);SDL_Quit();return 0;
}
