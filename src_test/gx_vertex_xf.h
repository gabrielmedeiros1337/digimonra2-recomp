// Host-only replica of the existing CPU XF pipeline, not guest CPU execution.
static const char* vertex_xf_source="#version 120\n" GLSL(
    varying vec2 depthZW;varying vec4 raster;varying vec3 tc[8];
    uniform vec4 points[66],normals[26],postMatrices[66],lights[32];
    uniform vec4 lightColors[8],lightMasks[4],ambientColor,materialColor;
    uniform ivec4 channelControl[2],channelAttenuation[2],texInfo[8],postInfo[8];
    uniform vec4 projectionData[2],viewportScale,viewportOffset;
    uniform int hasProjection,hasLighting,perspective;
    float component(vec4 v,int i){return v[i];}
    float normalElement(int i){return normals[i/4][i-(i/4)*4];}
    vec3 transformPoint(int index,vec3 inputValue){
        vec3 result;
        for(int r=0;r<3;r++){
            vec4 m=points[index+r];
            result[r]=((m.x*inputValue.x+m.y*inputValue.y)+m.z*inputValue.z)+m.w;
        }
        return result;
    }
    vec3 transformNormal(int index,vec3 inputValue){
        vec3 result;int base=(index-(index/32)*32)*3;
        for(int r=0;r<3;r++){
            int at=base+r*3;
            result[r]=(normalElement(at)*inputValue.x+normalElement(at+1)*inputValue.y)+normalElement(at+2)*inputValue.z;
        }
        float lengthValue=sqrt((result.x*result.x+result.y*result.y)+result.z*result.z);
        if(lengthValue>0.0)result/=lengthValue;
        return result;
    }
    vec4 illuminate(vec3 position,vec3 normalValue,vec4 raw){
        if(hasLighting==0)return raw;
        vec4 result;
        for(int channel=0;channel<4;channel++){
            int controlIndex=channel==3 ? 1:0;
            ivec4 control=channelControl[controlIndex];
            float material=control.x!=0 ? raw[channel]:materialColor[channel];
            if(control.y==0){result[channel]=material;continue;}
            float value=control.z!=0 ? raw[channel]:ambientColor[channel];
            for(int i=0;i<8;i++){
                if(lightMasks[controlIndex*2+i/4][i-(i/4)*4]==0.0)continue;
                float factor=1.0;int at=i*4;
                int attenuation=channelAttenuation[controlIndex].x;
                if(control.w!=0 || attenuation==3){
                    // Light words 10..12 and 13..15 straddle vec4 rows.
                    vec3 lightPosition=vec3(lights[at+2].zw,lights[at+3].x);
                    vec3 direction=lightPosition-position;
                    float distance2=(direction.x*direction.x+direction.y*direction.y)+direction.z*direction.z;
                    float distanceValue=sqrt(distance2);
                    if(distanceValue>0.0)direction/=distanceValue;
                    if(control.w!=0){factor=(normalValue.x*direction.x+normalValue.y*direction.y)+normalValue.z*direction.z;if(control.w!=1 && factor<0.0)factor=0.0;}
                    if(attenuation==3){
                        vec3 lightDirection=lights[at+3].yzw;
                        float cosine=-((direction.x*lightDirection.x+direction.y*lightDirection.y)+direction.z*lightDirection.z);
                        vec4 angular=lights[at+1],distanceCoefficients=lights[at+2];
                        float numerator=(angular.x+angular.y*cosine)+angular.z*cosine*cosine;
                        float denominator=(angular.w+distanceCoefficients.x*distanceValue)+distanceCoefficients.y*distance2;
                        factor*=numerator<=0.0 ? 0.0:denominator>0.0 ? numerator/denominator:1.0;
                    }
                }
                value+=factor*lightColors[i][channel];
            }
            value=clamp(value,0.0,255.0);
            result[channel]=clamp(floor(material*value/255.0+0.5),0.0,255.0);
        }
        return result;
    }
    void main(){
        vec3 position=gl_Vertex.xyz,normalValue=gl_Normal;
        vec3 raw[8];float matrixIndex[8];
        raw[0]=gl_MultiTexCoord0.xyz;matrixIndex[0]=gl_MultiTexCoord0.w;
        raw[1]=gl_MultiTexCoord1.xyz;matrixIndex[1]=gl_MultiTexCoord1.w;
        raw[2]=gl_MultiTexCoord2.xyz;matrixIndex[2]=gl_MultiTexCoord2.w;
        raw[3]=gl_MultiTexCoord3.xyz;matrixIndex[3]=gl_MultiTexCoord3.w;
        raw[4]=gl_MultiTexCoord4.xyz;matrixIndex[4]=gl_MultiTexCoord4.w;
        raw[5]=gl_MultiTexCoord5.xyz;matrixIndex[5]=gl_MultiTexCoord5.w;
        raw[6]=gl_MultiTexCoord6.xyz;matrixIndex[6]=gl_MultiTexCoord6.w;
        raw[7]=gl_MultiTexCoord7.xyz;matrixIndex[7]=gl_MultiTexCoord7.w;
        for(int coord=0;coord<8;coord++){
            vec3 stq=vec3(raw[coord].xy,1.0);ivec4 info=texInfo[coord],post=postInfo[coord];
            if(post.w!=0){
                vec3 source=raw[coord];if(info.x==0)source=position;else if(info.x==1)source=normalValue;else if(info.x>=5 && info.x<=12)source=raw[info.x-5];
                vec3 inputValue=vec3(source.xy,info.y!=0 ? source.z:1.0);
                int index=int(matrixIndex[coord]);
                if(index!=60 && info.z==0){
                    for(int r=0;r<3;r++){vec4 m=points[index+r];stq[r]=((m.x*inputValue.x+m.y*inputValue.y)+m.z*inputValue.z)+m.w;}
                    if(info.w==0)stq.z=1.0;
                }else stq.xy=source.xy;
                if(post.z!=0){
                    vec3 value=stq;
                    if(post.y!=0){float lengthValue=sqrt((value.x*value.x+value.y*value.y)+value.z*value.z);if(lengthValue>0.0)value/=lengthValue;}
                    for(int r=0;r<3;r++){vec4 m=postMatrices[post.x+r];stq[r]=((m.x*value.x+m.y*value.y)+m.z*value.z)+m.w;}
                }
            }
            tc[coord]=stq;
        }
        vec3 viewPosition=position;float w=1.0,clipZ=-0.5,z=0.5;vec2 xy=position.xy;
        if(hasProjection!=0){
            viewPosition=transformPoint(int(gl_Vertex.w),position);
            float projectedW=perspective!=0 ? -viewPosition.z:1.0;
            float inputZ=perspective!=0 ? viewPosition.z:1.0;
            float x=projectionData[0].x*viewPosition.x+projectionData[0].y*inputZ;
            float y=projectionData[0].z*viewPosition.y+projectionData[0].w*inputZ;
            if(abs(projectedW)>0.000001){
                w=projectedW;xy=vec2(x,y)*viewportScale.xy+(viewportOffset.xy-vec2(342.0))*w;
                clipZ=projectionData[1].x*viewPosition.z+projectionData[1].y;
                z=((clipZ/w)*viewportScale.z+viewportOffset.z)/16777215.0;
            }
        }
        gl_Position=vec4(xy.x/320.0-w,xy.y/264.0-w,0.0,w);
        gl_ClipVertex=vec4(0.0,0.0,clipZ,w);depthZW=vec2((z*2.0-1.0)*w,w);
        raster=illuminate(viewPosition,transformNormal(int(gl_Vertex.w),normalValue),floor(gl_Color*255.0+0.5));
    }
);
