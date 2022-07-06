#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 


int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        char str[n][m];
        for(int i = 0;i <n;i++){
            gets(str[i]);
            getchar();
        }
        int count;
        for(int i = 0;i <n;i++){
            for(int j = 0;j <m;j++){
                count = 0;
                if(str[i][j]=='*'){
                    count =-1;
                    // printf("str[%d][%d]=%d\n",i,j,count);
                }
                if(str[i][j]=='.'){
                    if(j-1>=0){
                        if(str[i][j]=='*'){
                            count= count+1;
                        }
                        if(i-1>=0&&str[i][j]=='*'){
                            count= count+1;
                        }
                        if(i+1<n&&str[i][j]=='*'){
                            count= count+1;
                        }
                    }
                    if(i-1>=0&&str[i][j]=='*'){
                        count= count+1;
                        }
                        if(i+1<n&&str[i][j]=='*'){
                            count= count+1;
                    }
                    if(j+1<m){
                        if(str[i][j]=='*'){
                            count= count+1;
                        }
                        if(i-1>=0&&str[i][j]=='*'){
                            count= count+1;
                        }
                        if(i+1<n&&str[i][j]=='*'){
                            count= count+1;
                        }
                    }
                }
                
                // str[i][j] = count;
                printf("str[%d][%d]=%d\n",i,j,count);
            }
        }
        
    for(int i = 0;i <n;i++){
        for(int j = 0;j <m;j++){
            printf("%d",str[i][j]);
        }
        printf("\n");
    }
    
    }

    return 0;
}








