#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100



typedef struct Gnode{
    int tag;                        //0代表结点是单元素，1代表结点是广义表
    union{
        int data;
        struct Gnode *sublist;
    }URegion;
    struct Gnode *next;
}Gnode,*GList;

GList init_list(int n);
void input_list(GList ptrl);
int length(GList ptrl);                              //O(n)
GList findk(int k,GList ptrl);                        //O(n)
GList findn(int n,GList ptrl);                        //O(n)
GList insert_list(int i,int n,GList ptrl);
GList delete_list(GList ptrl,int n);

