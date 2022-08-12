#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100

typedef struct Lnode{
    int data[Maxsize];
    int last;
}Lnode,*List;

//指针实现
List makeempty();                           //建立空线性表
List init_list(int n,List p);               //初始化线性表
int Find_list(List p,int x);                //查找元素x的位置
List insert_loci(int i,int m,List p);       //在位置i插入一个元素m(0<=i<=last)
List delete_list(List p,int i);             //删除第i个位置的元素(0<i<=last)

int main(){
    int n;
    scanf("%d",&n);
    List Ptrl = makeempty();
    Ptrl = init_list(n,Ptrl);
    // int x;
    // scanf("%d",&x);
    // int loc = Find_list(Ptrl,x);
    // printf("%d",loc);
    
    // int i,m;
    // scanf("%d %d",&i,&m);
    // Ptrl = insert_loci(i,m,Ptrl);
    // for(int i = 0;i <=Ptrl->last;i++){
    //     printf("%d ",Ptrl->data[i]);
    // }
    
    int i;
    scanf("%d",&i);
    Ptrl = delete_list(Ptrl,i);
    for(int i = 0;i <=Ptrl->last;i++){
        printf("%d ",Ptrl->data[i]);
    }
    

    return 0;
}


List makeempty(){
    List p = (Lnode *)malloc(sizeof(Lnode));
    p->last=-1;
    return p;
}

List init_list(int n,List p){
    for(int i = 0;i <n;i++){
        p->data[i] = 2*i;
        p->last+=1;  
    }
    return p;
}

int Find_list(List p,int x){
    for(int i = 0;i <=p->last;i++){                 //平均比较次数(1+n)/2，时间复杂度O(n)
        if(p->data[i]==x){
            return i;
        }
    }
    return -1;
}

List insert_loci(int i,int m,List p){               //平均比较次数(1+n)/2，时间复杂度O(n)
    if(i>Maxsize-1){
        printf("no room to insert\n");
        return p;
    }
    if(i<0||i>p->last){
        printf("out of range\n");
        return p;
    }

    int j = p->last+1;
    for(;j>i;j--){
        p->data[j] = p->data[j-1];
    }

    p->data[i] = m;
    p->last+=1;
    return p;
}

List delete_list(List p,int i){                 //平均比较次数(1+n)/2，时间复杂度O(n)
    if(i<0||i>p->last){
        printf("out of range\n");
        return p;
    }
    for(int j = i;j<p->last-1;j++){
        p->data[j] = p->data[j+1];
    }
    p->last-=1;
    
    return p;
}



// // 对象实现
// Lnode makeempty();
// Lnode init_node(int n,Lnode p);
// int Find_list(Lnode p,int x);
// Lnode insert_loci(int i,int m,Lnode p);       //在位置i插入一个元素m
// Lnode delete_list(Lnode p,int i);

// int main(){
//     int n;
//     scanf("%d",&n);
//     Lnode Ptrl = makeempty();
//     Ptrl = init_node(n,Ptrl);

//     // int x;
//     // scanf("%d",&x);
//     // int loc = Find_list(Ptrl,x);
//     // printf("%d",loc);

//     // int i,m;
//     // scanf("%d %d",&i,&m);
//     // Ptrl = insert_loci(i,m,Ptrl);
//     // for(int j = 0;j <=Ptrl.last;j++){
//     //     printf("%d ",Ptrl.data[j]);
//     // }

//     int i;
//     scanf("%d",&i);
//     Ptrl = delete_list(Ptrl,i);
//     for(int i = 0;i<=Ptrl.last;i++){
//         printf("%d ",Ptrl.data[i]);
//     }
//     return 0;
// }

// Lnode makeempty(){
//     Lnode p;
//     p.last = -1;
//     return p;
// }

// Lnode init_node(int n,Lnode p){
//     for(int i = 0;i <n;i++){
//         p.data[i] = 2*i;
//         p.last++;
//     }
//     return p;
// }

// int Find_list(Lnode p,int x){                    //平均比较次数(1+n)/2，时间复杂度O(n)
//     for(int i = 0;i <=p.last;i++){
//         if(p.data[i]==x){
//             return i;
//         }
//     }
//     return -1;
// }

// Lnode insert_loci(int i,int m,Lnode p){
//     if(i>Maxsize-1){
//         printf("no room to insert\n");
//         return p;
//     }
//     if(i<0||i>p.last){
//         printf("out of range\n");
//         return p;
//     }
//     for(int j = p.last+1;j>i;j--){
//         p.data[j] = p.data[j-1];
//     }
//     p.data[i] = m;
//     p.last++;
//     return p;
// }

// Lnode delete_list(Lnode p,int i){
//     if(i<0||i>p.last){
//         printf("out of range\n");
//         return p;
//     }
//     for(int j = i;j <p.last;j++){
//         p.data[j] = p.data[j+1];
//     }
//     p.last-=1;
//     return p;
// }