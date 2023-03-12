//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 


typedef char ElemType; 

//顺序栈 
typedef struct {
	ElemType *elem;
	int top;			//栈顶指针 
	int stacksize;		//当前分配的最大容量 
	int incrementsize;	//约定的增补空间量 
}SqStack;

//链式栈
typedef struct LNode{    
	ElemType date;
	struct LNode *next; 
}LNode,*LinkStack;

int main(){
	
}
