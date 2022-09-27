#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100

/*树与树的表示
层次关系
在管理上具有更高的效率


数据管理的基本操作之一：查找
静态查找：集合中记录是固定的，没有插入和删除操作
动态查找：除查找，还可能发生插入和删除

静态查找

方法一：顺序查找：时间复杂度为O(n)
typedef struct Lnode{
    int data[10];
    int length;
}Lnode,*List;
int LnodeSearch(List Q,int x){
    int i;
    Q->data[0] = 99;                        //哨兵
    for(i = Q->length;Q->data[i]!=99;i--);
    return i;
}

方法二：二分查找  时间复杂度O(logN)
假设n个数据元素的关键字满足基本有序，并且是连续存放（数组），那么可以进行二分查找。
基本实现：
查找444
5 16 39 45 51 98 100 202 226 321 368 444 501
1 2  3  4  5  6  7   8   9   10  11  12  13     
1.left = 1，right = 13 ， mid = （1+13）/2=7，比较发现data[mid]>444
2.left = mid+1=8， right = 13 ， mid = （8+13）/2=10，data[mid]<444
3.left = mid+1=11，right = 13 ， mid = （11+13）/2=12，data[12] ==444
查找43
1.left = 1，right = 13 ， mid = （1+13）/2=7，比较发现data[mid]>43
2.left = 1, right = mid-1=6,mid = (1+6)/2=3，data[3] = 39<43
3.left = mid+1=4， right = 6 ， mid = （4+6）/2=5，data[mid]=51>43
4.left = 4, right = mid-1=4,mid = (4+4)/2=4，data[4] = 45>43
5.left = 4, right = mid-1=3,left >right , 查找失败
typedef struct Lnode{
    int data[10];
    int length;
}Lnode,*List;
int BinarySearch(List Tbl,int x){
    int left=1,right=Tbl->length,mid;
    while(left<=right){
        mid = (left+right)/2;
        if(Tbl->data[mid]<x){
            left = mid+1;
        }
        else if(Tbl->data[mid]>x){
            right = mid-1;
        }
        else{
            return mid;
        }
    }
    return 0;
}

11个元素的二分查找判定树：
判定树上每个结点需要的查找次数刚好是该结点所在的层数
查找成功时查找次数不会超过判定树的深度
n个节点的判定树的深度是log2N+1向下取整
ASL = （4*4+4*3+2*2+1）/11=3  //平均查找长度：找四次的（第四层）四个结点，找三次的（第三层）四个节点

树的定义：n（n>=0）个结点构成的有限集合
当n=0时，称为空树
对于任意一棵
*/



/*二叉树及存储结构
二叉树的链表表示
typedef struct Binnode{
    int data;
    struct Binnode *left;                 //指向左子树
    struct Binnode *right;                //指向右子树
}Binnode,*BinTree;

typedef struct Snode{
    int data;
    int top;
}Snode,*Stack;

二叉树的遍历
先序遍历 根左右
void PreOrferTraversal(BinTree BT){
    if(BT){
        printf("%d",BT->data);
        PreOrferTraversal(BT->left);
        PreOrferTraversal(BT->right);
    }
}

中序遍历 左根右
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->left);
        printf("%d",BT->data);
        InOrderTraversal(BT->right);
    }
}

后序遍历 左右根
void PostOrderTraversal(BinTree BT){
    if(BT){
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        printf("%d",BT->data);
    }
}

非递归遍历
中序遍历的非递归遍历算法-基本思路：堆栈
i:碰到一个节点，压入栈，遍历它的左子树
ii:左子树遍历结束后，栈顶元素出栈并访问
iii:遍历该结点的右子树，重复i，ii

void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack(Maxsize);          //创建并初始化栈
    while(T||!Isempty(S)){                  //二叉树和栈都不为空
        while(T){
            Push(S,T);                      //二叉树不为空，压入左子树，当左子树为空，退出循环
            T=T->left;                      
        }
        if(!Isempty(S)){                    //检查堆栈是否为空，不为空，弹出栈顶元素并访问，并使访问该结点的右子树
            T = Top(S);
            printf("%d",T->data);
            T=T->right;
        }
    }
}

先序遍历的非递归
i:碰到第一个结点，先访问，然后压入栈，遍历该节点的左子树（输出所有的根节点）
ii:左子树遍历结束。弹出栈顶元素，遍历该节点的右子树。重复i
void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack(Maxsize);          //创建并初始化栈
    while(T||!Isempty(S)){                  //二叉树和栈都不为空
        while(T){
            printf("%d",T->data);
            Push(S,T);                      //二叉树不为空，压入左子树，当左子树为空，退出循环
            T=T->left;                      
        }
        if(!Isempty(S)){                    //检查堆栈是否为空，不为空，弹出栈顶元素并访问，并使访问该结点的右子树
            T = Top(S);
            T=T->right;
        }
    }
}

后序遍历的非递归
i:创建两个堆栈，Q用于出栈访问，S用于入栈访问
ii:先遍历所有的右子树，依次压入Q和S中
iii：右子树遍历结束，从S中弹出栈顶元素，并访问该节点的左子树，重复i，ii
需要用到两个堆栈，第一个堆栈和中序遍历里的堆栈一样，第一次访问入栈，第二次访问出栈，但在第二次访问时应在出第一个栈时压入第二个栈，在访问到右子树为空时出栈并输出
void PostOrderTraversal2(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack();                //创建并初始化堆栈S
    Stack Q = CreateStack();                //创建并初始化堆栈Q，用于输出反向
    while(T || !IsEmpty(S)){
        while(T){                           //一直向右并将沿途结点压入堆栈
            Push(T, S);
            Push(T, Q);                     //将遍历到的结点压栈，用于反向
            T = T->Right;
        }
        if(!IsEmpty(S)){
            T = Pop(S); //结点弹出堆栈
            T = T->Left; //转向左子树
        }
    }
    while(!IsEmpty(Q)){
        T = Pop(Q);
        printf("%d ", T->Data);             //（访问）打印结点
    }
}

层序遍历-队列
i:先访问根（父）节点，将其左右儿子放进队列中
ii:根（父）结点出队，将队列中下一个结点的左右儿子放进队列中，重复i，ii



*/
typedef struct Binnode{
    int data;
    struct Binnode *left;                 //指向左子树
    struct Binnode *right;                //指向右子树
}Binnode,*BinTree;


typedef struct Qnode{
    int data;
    struct Qnode *next;
}Qnode,*Queue;

typedef struct Node{
    Queue near,front;
}Node,*node;

void LevelOrderTraversal(BinTree BT){
    Queue Q;
    BinTree T;
    if(!BT){
        return;
    }
    Q = CreatQueue(Maxsize);
    AddQ(Q,BT);                             //根节点放到队列Q中
    while(!IsemptyQ(Q)){                    //判断队列Q是否为空，不为空进入循环
        T = DeleteQ(Q);                     //弹出队列的第一个元素
        printf("%d",T->data);
        if(T->left){                        //将该元素的左右子节点加入队列中
            AddQ(Q,T->left);
        }
        if(T->right){
            AddQ(Q,T->right);
        }
    }

}

//输出二叉树所有的叶子节点
void PreOrderTraversal(BinTree BT){
    if(BT){
        if(!BT->right&&!BT->right){
            printf("%d",BT->data);
        }
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}


//求二叉树的高度
int PostOrderGetHeight(BinTree BT){
    int HL=0,HR=0,MAXH=0;
    if(BT==NULL){
        return 0;
    }
    if(BT->left==NULL&&BT->right==NULL){
        return 1;
    }
    if(BT){
        HL += PostOrderGetHeight(BT->left);
        HR += PostOrderGetHeight(BT->right);
        MAXH = HL>HR?HL:HR;
        return MAXH+1;
    }
    else return 0;
}

