#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 

int main(){
    int n,m;
    char str[100][100];
    
    while(~scanf("%d %d",&n,&m)){
        for(int i = 0;i <n;i++){
            for(int j = 0;j <m;j++){
                scanf("%c",&str[i][j]);
            }
            getchar();
        }

        int count;
        for(int i = 0;i <n;i++){
            for(int j = 0;j <m;j++){
                count = 0;

                if(str[i][j] == '*'){
                    printf("%c",str[i][j]);
                }
                
                if(str[i][j]=='.'){
                    if(j-1>=0){
                        if(str[i][j-i]=='*'){
                            count= count+1;
                        }
                        if(i-1>=0&&str[i-1][j-1]=='*'){
                            count= count+1;
                        }
                        if(i+1<n&&str[i+1][j-1]=='*'){
                            count= count+1;
                        }
                    }
                    if(i-1>=0&&str[i-1][j]=='*'){
                        count= count+1;
                        }
                    if(i+1<n&&str[i+1][j]=='*'){
                        count= count+1;
                    }
                    if(j+1<m){
                        if(str[i][j+1]=='*'){
                            count= count+1;
                        }
                        if(i-1>=0&&str[i-1][j+1]=='*'){
                            count= count+1;
                        }
                        if(i+1<n&&str[i+1][j-1]=='*'){
                            count= count+1;
                        }
                    }
                    printf("%d",count);
                }  
            }
            printf("\n");
        }
    }

    return 0;
}





