#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 

double check(double IRR,int t,int n[]);

int main(){
    int t,a[11];
    double x,y,IRR;
    while(scanf("%d",&t)&&t){
        for(int i = 0;i <=t;i++){
            scanf("%d",&a[i]);
        }
        x = 1e-6,y = 1e6,IRR;
        do{
            IRR = (x+y)/2;
            if(check(x,t,a)*check(IRR,t,a)<0){
                y = IRR;
            }
            else if(check(IRR,t,a)*check(y,t,a)<0){
                x = IRR;
            }
            else if(check(IRR,t,a)==0){
                break;
            }
        }while(fabs(check(x,t,a)-check(y,t,a))>1e-6);
        printf("%.2f\n",IRR);
    }
    return 0;
}

double check(double IRR,int t,int n[]){
    double NPV = 0;
    for(int i = 0;i <=t;i++){
        NPV +=n[i]/pow(1+IRR,i);
    }
    return NPV;
}
