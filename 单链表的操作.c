#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h> 
#include<time.h>
#define Maxsize 100



typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*List;

List init_list(int n);
void input_list(List ptrl);
int length(List ptrl);                              //O(n)
List findk(int k,List ptrl);                        //O(n)
List findn(int n,List ptrl);                        //O(n)
List insert_list(int i,int n,List ptrl);
List delete_list(List ptrl,int n);

int main(){
    List ptrl = (List)malloc(sizeof(Lnode));
    ptrl = init_list(10);
    input_list(ptrl);
    int n;
    n = length(ptrl);
    printf("%d",n);
    printf("\n");
    int i,j;
    scanf("%d %d",&i,&j);
    ptrl = insert_list(i,j,ptrl);
    input_list(ptrl);
    scanf("%d",&i);
    ptrl = delete_list(ptrl,i);
    input_list(ptrl);
    return 0;
}
List init_list(int n){
    List p = (List)malloc(sizeof(Lnode));
    p->next = NULL;
    List head = p;
    for(int i = 0;i <10;i++){
        List tmp = (List)malloc(sizeof(Lnode));
        tmp->data = i*2;
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
    }
    return head;
}

void input_list(List ptrl){
    List p = ptrl->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length(List ptrl){
    int j = 0;
    List p = ptrl->next;
    while(p){
        p = p->next;
        j++;
    }
    return j;
}

List findk(int k,List ptrl){
    List p = ptrl->next;
    int i = 1;
    while(p!=NULL&&i<k){
        p = p->next;
        i++;
    }
    if(i==k){
        return p;
    }
    else{
        return NULL;
    }

}
List findn(int n,List ptrl){
    List p = ptrl->next;
    while(p!=NULL&&p->data!=n){
        p = p->next;
    }
    return p;
}

List insert_list(int i,int n,List ptrl){
    List p = ptrl->next;
    if(i == 1){
        List tmp = (List)malloc(sizeof(Lnode));
        tmp ->next = p;
        ptrl->next = tmp;
        tmp->data = n;
        return ptrl;
    }

    // for(int j = 1;j <i-1;j++){
    //     p = p->next;
    // }
     
    p = findk(i-1,ptrl);
    if(p==NULL){
        printf("out of range\n");
        return ptrl;
    }
    else{
        List tmp = (List)malloc(sizeof(Lnode));
        tmp ->next = p->next;
        tmp ->data = n;
        p->next = tmp;
        return ptrl;
    }
}


List delete_list(List ptrl,int n){
    List p;
    if(n == 1){
        p = ptrl->next;
        ptrl->next = p->next;
        free(p);
        return ptrl;
    }
    p = findk(n-1,ptrl);
    if(p ==NULL||p->next==NULL){
        printf("out of range\n");
        return ptrl;
    }
    else{
        List tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return ptrl;
    }
}

