#include <stdio.h>
#include <math.h>
#include<stdlib.h>

struct node{
    int data;
    int conut;
    struct node* next;
};

bool containsDuplicate(int* nums, int numsSize);
int main(){
	int i;
	int nums[10000];
	for(i=1;i<=10000;i++){
		nums[i-1]=i;
	}
	nums[500]=500;
	printf("%d",containsDuplicate(nums,10000));
	
} 
bool containsDuplicate(int* nums, int numsSize){
	
    struct node* temp=(node*)malloc(sizeof(struct node)*numsSize);
    for(int i=0;i<numsSize;i++){
        temp[i].data=0;
        temp[i].conut=0;
        temp[i].next=NULL;
    }
    for(int i=0;i<numsSize;i++){
        if(temp[abs(nums[i]%numsSize)].conut==0){
            temp[abs(nums[i]%numsSize)].data=nums[i];
            temp[abs(nums[i]%numsSize)].conut++;
        }
        else{
            struct node* p=&temp[abs(nums[i]%numsSize)];
            struct node* prev=p;
            while(p!=NULL){
                if(p->data==nums[i])
                return true;
                prev=p;
                p=p->next;
            }
            struct node* news=(node*)malloc(sizeof(struct node));
            news->data=nums[i];
            news->next=NULL;
            prev->next=news;
            
        }
    }
    return false;
}
