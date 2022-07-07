#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 


int main(){
    int n,m;
    char str[100][100];
    
    while(~scanf("%d %d",&n,&m)){
        if(n==0&&m==0){
            break;
        }

        else{
            for(int i = 0;i <n;i++){                        //输入扫雷地图
                for(int j = 0;j <m;j++){
                    scanf("%c",&str[i][j]);
                }
                getchar();
            }

            int count = 0,leftj,rightj;
            for(int i = 0;i <n;i++){
                for(int j = 0;j <m;j++){

                    if(str[i][j] =='*'){
                        printf("%c",str[i][j]);
                    }

                    
                    if(str[i][j] =='.'){

                        leftj = j-1;                         //左边三排
                        if(leftj>=0){                         
                            if(str[i][leftj]=='*'){
                                count= count+1;
                            }
                            if(i-1>=0&&str[i-1][leftj]=='*'){
                                count= count+1;
                            }
                            if(i+1<n&&str[i+1][leftj]=='*'){
                                count= count+1;
                            }
                        }

                        if(i-1>=0&&str[i-1][j]=='*'){       //正上
                            count= count+1;
                            }
                        if(i+1<n&&str[i+1][j]=='*'){        //正下
                            count= count+1;
                        }

                        rightj = j+1;
                        if(rightj<m){                          //右边三排
                            if(str[i][rightj]=='*'){
                                count= count+1;
                            }
                            if(i-1>=0&&str[i-1][rightj]=='*'){
                                count= count+1;
                            }
                            if(i+1<n&&str[i+1][rightj]=='*'){
                                count= count+1;
                            }
                        }
                        printf("%d",count);
                        count = 0;
                    }  

                    
                }
                printf("\n");
            }

        }
        

        
        
    }

    return 0;
}











