//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int STACKINIT_SIZE=100;
const int STACKINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 


typedef int ElemType; 

//顺序栈 
typedef struct {
	ElemType *elem;
	int top;			//栈顶指针 
	int stacksize;		//当前分配的最大容量 
	int incrementsize;	//约定的增补空间量 
}SqStack;


void InitStack_Sq(SqStack &S,int maxsize,int incresize);
         
void Push_Sq(SqStack &S,ElemType e);

bool Pop_Sq(SqStack &S,ElemType &e);
void Incrementsize_Sq(SqStack &S); 
void Stack_Traverse_Sq(SqStack S);

int main(){
	
	
	//顺序栈的操作验证 
	SqStack S;
	ElemType N;
	cin>>N;
	
	
	//初始化 
	InitStack_Sq(S,100,10);
	
	//入栈 
	while(N!=0){
		Push_Sq(S,N%8);
		N=N/8;
	}
	
	//输出 
	Stack_Traverse_Sq(S);

}

//顺序栈初始化 
void InitStack_Sq(SqStack &S,int maxsize,int incresize){
	 
	S.elem = new ElemType[maxsize];
	
	S.top=-1;
	
	S.stacksize=maxsize;
	
	S.incrementsize=incresize;
} //InitStack_Sq



//顺序栈的插入 
void Push_Sq(SqStack &S,ElemType e){
	if(S.top+1==S.stacksize) Incrementsize_Sq(S);//空间扩容
	S.elem[++S.top]=e;
}//Push_Sq

//栈扩容 
void Incrementsize_Sq(SqStack &S){
	ElemType A[S.top+S.incrementsize+1];
	ElemType *B;

	for(int i=0;i<=S.top;i++) A[i]=S.elem[i];
	
	S.stacksize=S.top+S.incrementsize+1;
	
	B=S.elem;	
	S.elem=A;	
	free(B);
}



//删除栈顶元素，并用 e 承接 
bool Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==-1) return FALSE;
	e=S.elem[S.top--];
	
	return TRUE;	
}





//顺序栈输出
void Stack_Traverse_Sq(SqStack S){
	int i;
	ElemType e;
	if(S.top==-1) printf("空栈"); 
	for(i=S.top;i>=0;i--){
		Pop_Sq(S,e);
		cout<<e<<endl;
	}
	
} 






