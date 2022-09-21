#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100

//多项式实现
typedef struct PolyNode{
    int coef;                                       //系数
    int expon;                                      //指数
    struct PolyNode *link;                          //指向下一个结点的指针
}PolyNode,*Polynomial;

PolyNode P1,P2;

/*
算法思路：两个指针分别指向两个多项式的第一个结点，不断循环：
P1->expon == P2->exopn：系数相加，若结果不为零，则作为结果多项式对应项新的系数。同时，P1、P2的指针指向下一项。
P1->expon > P2->exopn：将P1的结果存入多项式，并使P1指向下一项
P1->expon < P2->exopn：将P2的结果存入多项式，并使P2指向下一项
当某一多项式处理完时，将另一个多项式的剩余结点依次复制到结果多项式中去
*/

Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    Polynomial front,rear,tmp;                                  //多项式的头和尾
    int sum;
    rear = (Polynomial)malloc(sizeof(PolyNode));
    front = rear;
    while(P1&&P2){                                              //两个多项式都不为空
        switch(compare(P1->expon,P2->expon)){                   //compare：比较大小，第一个大，返回1；第二个大，返回-1；相等，返回0
            case 1:
                Attach(P1->coef,P1->expon,&rear);               //接到rear后面
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2 = P2->link;
                break;
            case 0:
                sum = P1->coef+P2->coef;
                if(sum){
                    Attach(sum,P1->expon,&rear);
                }
                P1 = P1->link;
                P2 = P2->link;
                break;
        }
    }

    for(;P1;P1=P1->link){
        Attach(P1->coef,P1->expon,&rear);
    }
    for(;P2;P2=P2->link){
        Attach(P2->coef,P2->expon,&rear);
    }
    rear->link = NULL;
    tmp = front;
    front = front->link;
    free(tmp);
    return front;
}

void Attach(int c,int e,Polynomial *Rear){                      //引入指针的指针
    Polynomial P = (Polynomial)malloc(sizeof(PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*Rear)->link = P;                                          //*rear表示这个指针指向rear
    *Rear = P;
}

/*例题：
设计函数分别求两个一元多项式的成绩与和
###输入样例：
4 3 4 -5 2 6 1 -2 0
3 5 20 -7 4 3 1

###输出样例：
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1 
5 20 -4 4 -5 2 9 1 -2 0
*/

/*思路：
1.多项式如何表示
数组：
编程简单，调试容易
需要事先确定数组大小

链表：
动态性强
变成略微复杂，调试困难

本题已经给了具体的项数，所以可以使用动态数组，用malloc去申请空间输入多项式的每一项。
2.程序框架
3.如何读入多项式
4.加法实现
5.乘法实现
6.多项式输出
*/

//链表实现
typedef struct PolyNode{
    int corf;
    int expon;
    struct PolyNode *next;
}PolyNode,*Polynomial;

Polynomial ReadPoly();
Polynomial Add(Polynomial P1,Polynomial P2);
void PolyAttach(int i,int j,Polynomial *Rear);
int PrintPoly(Polynomial P);
Polynomial Mult(Polynomial P1,Polynomial P2);

int main(){
    Polynomial P1,P2,PP,PS;
    
    P1 = ReadPoly();//读入多项式1
    P2 = ReadPoly();//读入多项式2
    PS = Add(P1,P2);
    PrintPoly(PS);//加法运算并输出
    PP = Mult(P1,P2);
    PrintPoly(PP);//乘法运算并输出
    

    return 0;
}

//带头结点
Polynomial ReadPoly(){
    int n;
    scanf("%d",&n);
    Polynomial head = (Polynomial)malloc(sizeof(PolyNode));
    head->next = NULL;
    Polynomial p = head;
    for(int i = 0;i<n;i++){
        Polynomial tmp = (Polynomial)malloc(sizeof(PolyNode));
        tmp->next = NULL;
        scanf("%d %d",&tmp->corf,&tmp->expon);
        p->next = tmp;
        p = tmp;
    }
    return head;
}



Polynomial Add(Polynomial P1,Polynomial P2){
    Polynomial t1 = P1->next,t2=P2->next;
    Polynomial P=(Polynomial)malloc(sizeof(PolyNode));
    P->next = NULL;
    Polynomial rear = P;
    int sum;
    while(t1&&t2){
        if(t1->expon>t2->expon){
            PolyAttach(t1->corf,t1->expon,&rear);
            t1=t1->next;
        }
        else if(t1->expon == t2->expon){
            sum = t1->corf+t2->corf;
            PolyAttach(sum,t1->expon,&rear);
            t1=t1->next;
            t2=t2->next;
        }
        else{
            PolyAttach(t2->corf,t2->expon,&rear);
            t2=t2->next;
        }
    }
    while(t1){
        PolyAttach(t1->corf,P1->expon,&rear);
        t1=t1->next;
    }
    while(t2){
        PolyAttach(t2->corf,t2->expon,&rear);
        t2=t2->next;
    }
    return P;
}


void PolyAttach(int i,int j,Polynomial *Rear){
    Polynomial P = (Polynomial)malloc(sizeof(PolyNode));
    P->corf = i;
    P->expon = j;
    P->next = NULL;
    (*Rear)->next = P;
    *Rear = P;
}

int PrintPoly(Polynomial P){
    P=P->next;
    if(!P){
        printf("0\n");
        return 0;
    }
    while(P){
        printf("%d %d",P->corf,P->expon);
        P=P->next;
        if(P){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

/*乘法运算：
将乘法转化为加法运算：将p1当前项和p2相乘，在加入到结果多项式中。
逐项插入：将p1的当前项和p2的当前项相乘，并插入到结果多项式中，关键是要找到插入位置。初始结果多项式可由p1第一项乘p2获得*/

// //转换加法
// Polynomial Mult(Polynomial P1,Polynomial P2){
//     Polynomial t1 = P1->next;
//     Polynomial PP =(Polynomial)malloc(sizeof(PolyNode));
//     PP->next = NULL;
//     while(t1){
//         Polynomial P = (Polynomial)malloc(sizeof(PolyNode));
//         P->next = NULL;
//         Polynomial rear = P;
//         Polynomial t2 = P2->next;
//         while(t2){
//             PolyAttach(t1->corf*t2->corf,t1->expon+t2->expon,&rear);
//             t2=t2->next;
//         }
//         PP = Add(PP,P);
//         t1 = t1->next;

//     }
//     return PP;

// }

//逐项插入
                                                
Polynomial Mult(Polynomial P1,Polynomial P2){
    Polynomial t1 = P1->next,t2 = P2->next;
    int c,e;
    Polynomial P = (Polynomial)malloc(sizeof(PolyNode));
    P->next = NULL;
    Polynomial rear = P;
    if(!t1||!t2){
        return NULL;
    }

    while(t2){
        PolyAttach(t1->corf*t2->corf,t1->expon+t2->expon,&rear);
        t2=t2->next;
    }

    t1 = t1->next;
    
    while(t1){
        t2 = P2->next;
        rear = P;
        Polynomial tmp;
        while(t2){
            c = t1->corf*t2->corf;
            e = t1->expon+t2->expon;
            while(rear->next&&rear->next->expon>e){
                rear = rear->next;
            }
            if(rear->next&&rear->next->expon ==e){
                if(rear->next->corf+c){
                    rear->next->corf +=c;
                }
                else{
                    tmp = rear->next;
                    rear->next = tmp->next;
                    free(tmp);
                }
            }
            else{
                tmp = (Polynomial)malloc(sizeof(PolyNode));
                tmp->next= rear->next;
                tmp->corf = c;
                tmp->expon = e;
                rear->next = tmp;
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    return P;


}


// //不带头结点
// Polynomial ReadPoly(){
//     int n;
//     scanf("%d",&n);
//     Polynomial head = NULL;
//     // Polynomial head = (Polynomial)malloc(sizeof(PolyNode));
//     Polynomial r = head;
//     for(int i = 0;i<n;i++){
//         Polynomial tmp = (Polynomial)malloc(sizeof(PolyNode));
//         tmp->next = NULL;
//         scanf("%d %d",&tmp->corf,&tmp->expon);
//         if(head == NULL){   
//             head = tmp;
//             r = head;
//         }

//         // if(i == 0){         
//         //     head = tmp;
//         //     r = head;
//         // }

//         else{ 
//             r->next = tmp;
//             r = tmp;
//         }
//     }
//     return head;
// }

