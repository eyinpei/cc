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