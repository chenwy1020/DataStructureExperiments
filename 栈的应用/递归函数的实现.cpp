//10200115 
//陈文宇 
#include<iostream>
using namespace std;
const int STACKINIT_SIZE=100;
const int STACKINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef struct ElemType{
	int nval;
	int xval;
	int yval;
}ElemType;

typedef struct SqStack{
	ElemType *elem;
	int top;			//栈顶指针 
	int stacksize;		//当前分配的最大容量 
	int incrementsize;	//约定的增补空间量 
}SqStack;



//顺序栈初始化 
void InitStack_Sq(SqStack &S,int maxsize,int incresize){
	 
	S.elem = new ElemType[maxsize];
	
	S.top=-1;
	
	S.stacksize=maxsize;
	
	S.incrementsize=incresize;
} //InitStack_Sq

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

//判断顺序栈是否为空栈 
bool StackEmpty_Sq(SqStack S){
	if(S.top==-1) return TRUE;
	else return FALSE;
}

//获取栈顶元素，并用 e 承接 
void GetTop_Sq(SqStack S,ElemType &e){
	e=S.elem[S.top];	
}

//删除栈顶元素，并用 e 承接 
bool Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==-1) return FALSE;
	e=S.elem[S.top--];
	
	return TRUE;	
}

//顺序栈的插入 
void Push_Sq(SqStack &S,ElemType e){
	if(S.top+1==S.stacksize) Incrementsize_Sq(S);//空间扩容
	S.elem[++S.top]=e;
}//Push_Sq

int value(int n,int x,int y){
	if(n==0) return x+1;
	else switch(n){
		case 1:return x;
		case 2:return 0;
		case 3:return 1;
		default :return 2;
	}//switch
}//value

int Ackerman(int n,int x,int y){
	ElemType e;
	SqStack S;
	int u;
	
	InitStack_Sq(S,100,10);
	e.nval=n; e.xval=x; e.yval=y; Push_Sq(S,e);
	
	while(!StackEmpty_Sq(S)){
		
		GetTop_Sq(S,e);
		while(e.nval!=0 && e.yval!=0){
			e.yval--;
			Push_Sq(S,e);
		}//while
		
		Pop_Sq(S,e);
		u=value(e.nval,e.xval,e.yval);
		
		if(!StackEmpty_Sq(S)){
			Pop_Sq(S,e);
			e.nval--; e.yval=e.xval; e.xval=u;
			Push_Sq(S,e);
		}//if
	}//while
	
	return u;
}//Ackerman

int main(){
	cout<<Ackerman(3,2,1)<<endl;
}
