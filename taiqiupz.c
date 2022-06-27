#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 

//L,W,x,y,R,a,v,s
//右上角在(L,W)的矩形。 球心在(x,y) 半径为R 极角为a的射线   速率为v，s个时间单位
//x和y应四舍五入保留两位小数。


int main(){
    float L,W,x,y,R,a,v,s;
    float ys,xs;
    while(scanf("%f %f %f %f %f %f %f %f",&L,&W,&x,&y,&R,&a,&v,&s)){
        if(L==0&&W==0){
            return 0;
        }
        else{
            ys = v*s*sin(a*M_PI/180);
            y = y+ys;
            while(y<R || y>W-R){            //越界判断(为什么要判断y<R？)
                if(y<R){
                    y = 2*R-y;
                }
                else{
                    y = 2*(W-R)-y;
                }
            }
                            
            xs=v*s*cos(a*M_PI/180);//x方向总路程
            x += xs;
                    
            while(x<R || x>L-R){            //越界判断 
                if(x<R){
                    x = 2*R-x;
                }
                else{
                    x = 2*(L-R)-x;
                }
            }
                    
            x = (int)(x*100+0.5)/100.0;//四舍五入
            y = (int)(y*100+0.5)/100.0;
                    
            printf("%.2f %.2f\n",x,y);    
        }
           
        }

}


