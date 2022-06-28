#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h> 

void wiggleSort(int* nums, int numsSize);
int main(){
    int numsSize =13;
    int n[numsSize];
    for(int i = 0;i <numsSize;i++){
        scanf("%d",&n[i]);
    }
    wiggleSort(n,numsSize);
    
    for(int i = 0;i<numsSize;i++){
        printf("%d",n[i]);
    }
    return 0;
}

void wiggleSort(int nums[], int numsSize){
    int tmp;
    for(int i = 0;i<numsSize;i++){
        int max = i;
        for(int j = i;j <numsSize;j++){    
            max = nums[j]>nums[max]?j:max;
        }
        if(max!=i){
            tmp = nums[max];
            nums[max] = nums[i];
            nums[i] = tmp;
        }   
    }
    
    int i = 0,mid = numsSize/2;
        
    for(;i<numsSize-1;i+=2){
        tmp = nums[mid];
        for(int t = mid;t>i;t--){
            nums[t] = nums[t-1];
        }
        nums[i] = tmp;
        mid +=1;
    }
}

