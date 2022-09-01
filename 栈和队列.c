#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100

//数组实现堆栈
typedef struct Snode{
    int data[Maxsize];
    int top;                                    //top = -1表示栈空
}Snode,*Stack;

Stack CreatStack();                  //生成空栈。最大长度为Maxsize
int IsFull(Stack PtrS);             //判断栈是否满了
void Push(Stack PtrS,int n);                    //将元素n压入栈
int IsEmpty(Stack PtrS);                        //判断栈是否为空
int Pop(Stack PtrS);                            //找到并删除栈顶元素

void Push(Stack PtrS,int n){
    if(PtrS->top==Maxsize-1){
        printf("out of range");
        return;
    }
    PtrS->data[++(PtrS->top)]=n;
    return 0;
}

int Pop(Stack PtrS){
    if(PtrS->top==-1){
        printf("is empty");
        return 0;
    }
    return (PtrS->data[PtrS->top--]);
}

//用数组实现两个堆栈，要求只要数组有空间，就可以进行入栈
typedef struct DSnode{
    int data[Maxsize];
    int top1;
    int top2;
}DSnode,*DStack;
//top1 = -1;
//top2 = Maxsize;

void PushD(DStack ptrs,int n,int Tag){                      //tag作为区分两个堆栈的标志，取值为1和2
    if(ptrs->top2-ptrs->top1 == 1){
        printf("is full");
        return;
    }
    if(Tag==1){
        ptrs->data[++ptrs->top1]==n;
    }
    else{
        ptrs->data[--ptrs->top2]==n;
    }
}                   

int pop(DStack ptrs,int Tag){
    if(Tag ==1){
        if(ptrs->top1==-1){
            printf("1 is empty");
            return 0;
        }
        else{
            return (ptrs->data[(ptrs->top1)--]);
        }
    }
    else{
        if(ptrs->top2==Maxsize){
            printf("2 is empty");
            return 0;
        }
        else{
            return (ptrs->data[(ptrs->top1)++]);
        }
    }
}



//链表实现堆栈
typedef struct Snode{
    int data;
    struct Stack *next;
}Snode,*Stack;

Stack CreatStack(){
    Stack ptrls = (Stack)malloc(sizeof(Snode));
    ptrls->next= NULL;
    return ptrls;
}

int IsEmpty(Stack ptrls){
    return (ptrls->next==NULL);             //为空，返回1；不为空，返回0；
}

void Push(Stack ptrls,int n){
    Stack tmp = (Stack)malloc(sizeof(Snode));
    tmp->next = ptrls->next;
    tmp->data = n;
    ptrls->next = tmp;
}

int Pop(Stack ptrls){
    Stack top = ptrls->next;
    int tmp;
    if(ptrls->next==NULL){
        printf("is empty");
        return 0;
    }
    else{
        ptrls->next = top->next;
        tmp = top->data;
        free(top);
        return tmp;
    }
}

//表达式求值
/*中缀转后缀------
运算数，输出；
左括号，压入栈；
右括号，依次出栈直到左括号出栈（括号出栈，但是不输入）
运算符：
    a.优先级大于栈顶运算符，压入栈；
    b.优先级小于栈顶优先级，栈顶元素出栈，比较新的栈顶元素，直到该运算符优先级大于新的栈顶元素，将其压入栈。优先级相同，左边的高。
对象处理完毕，栈中元素依次出栈*/

//堆栈应用
//函数调用及递归实现、深度优先搜索、回溯算法

//队列：顺序存储（数组实现）和链式存储
typedef struct Qnode{
    int data[Maxsize];
    int front;
    int rear;
}Qnode,*Queue;

Queue CreatQueue();
int IsFull(Queue PtrQ);                                
//循环队列队满解决方案
//1、使用额外标记，size表示数量，入加出减，size=maxsize表示队满；使用tag，入为0.出为1，front == rear时，查看tag状态，入则为满，出则为空
//2、队列只放n-1个元素
void AddQueue(Queue PtrQ,int item);
int IsEmpty(Queue PtrQ);
int DeleteQueue(Queue PtrQ);


Queue CreatQueue();
int IsFull(Queue PtrQ);

void AddQueue(Queue PtrQ,int item){
    if((PtrQ->rear+1)%Maxsize==PtrQ->front){
        printf("is full");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%Maxsize;
    PtrQ->data[PtrQ->rear] = item;
}

int IsEmpty(Queue PtrQ);

int DeleteQueue(Queue PtrQ){
    if(PtrQ->rear==PtrQ->front){
        printf("is empty");
        return 0;
    }
    PtrQ->front = (PtrQ->front+1)%Maxsize;
    return PtrQ->data[(PtrQ->front)];
}


//链式存储：队列的头为链表的front（方便进行删除）
typedef struct Node{
    int data;
    struct Node *next;
}Node,*node;

typedef struct Qnode{
    node rear,front;
}Qnode,*Queue;


//不带头结点的链式队列的出队操作
int deleteQueue(Queue ptrlq){
    if(ptrlq->front==NULL){
        printf("is empty");
        return 0;
    }
    node frontcell = ptrlq->front;                  //frontcell为需要出队的结点
    if(ptrlq->front==ptrlq->rear){
        ptrlq->front=ptrlq->rear=NULL;              
    }
    else{
        ptrlq->front = ptrlq->front->next;          //ptrlq->front指向下一个结点（后移）
    }
    int frontelem = frontcell->data;                
    free(frontcell);
    return frontelem;
}

void addQueue(Queue ptrlq,int item){
    node tmpq = (node)malloc(sizeof(Node));         //申请一个空的结点
    tmpq->next=NULL;                                //赋值
    tmpq->data =item;
    if(ptrlq->front==NULL){
        ptrlq->front = ptrlq->rear = tmpq;          //front和rear指向新的结点
    }
    else{
        ptrlq->rear->next = tmpq;                   //rear指向新的结点
        ptrlq->rear = tmpq;                         //rear等于新的结点
    }
}





