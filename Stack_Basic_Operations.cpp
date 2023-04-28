//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int STACKINIT_SIZE=100;
const int STACKINCREMENT=10;
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
typedef struct LNode{    //typedef是用来设置结构体别名，使用过后 定义结构体可以 LNode p ;LNode *p;有简化的效果 
	ElemType date;
	struct LNode *next; //结构体自引用-next作为指针 指向 结构体; 
}LNode,*LinkList;    // LinkList 是通过结构体声明的指针变量（结构体指针），相当于LNode *LinkList;  LinkList是指向该种结构体的指针 
//LNode本身就是一个结构体，但是它的命名是一个指针类型。 

typedef LinkList LinkStack;

//函数声明
//此处 & 表引用声明，相当于目标变量有两个名称，即该目标原名称和引用名，且不能再把该引用名作为其他变量名的别名
//它和 位运算符和指针运算符 没有关系 
//一般引用是通过定义通过同类型的变量 赋值，函数结束后则释放内存，引用指针则是直接对地址存放的值运算，可以保证不被释放 
void InitStack_Sq(SqStack &S,int maxsize,int incresize);
void DestroyStack_Sq(SqStack &S);
void ClearStack_Sq(SqStack &S);
bool StackEmpty_Sq(SqStack S);           
void Push_Sq(SqStack &S,ElemType e);
void GetTop_Sq(SqStack S,ElemType &e);
bool Pop_Sq(SqStack &S,ElemType &e);
void Incrementsize_Sq(SqStack &S);
void Stack_Traverse_Sq(SqStack S);

int main(){
	
	
	//顺序栈的操作验证 
	SqStack S;
	ElemType e;
	
	//初始化 
	InitStack_Sq(S,100,10);
	
	//入栈 
	Push_Sq(S,'a');
	Push_Sq(S,'b');
	Push_Sq(S,'c');
	Push_Sq(S,'d');
	
	Stack_Traverse_Sq(S);

	//出栈
	Pop_Sq(S,e); 
	Stack_Traverse_Sq(S);
	
	//链栈的验证 
}

//顺序栈初始化 
void InitStack_Sq(SqStack &S,int maxsize,int incresize){
	 
	S.elem = new ElemType[maxsize];
	
	S.top=-1;
	
	S.stacksize=maxsize;
	
	S.incrementsize=incresize;
} //InitStack_Sq


//顺序栈的销毁
void DestroyStack_Sq(SqStack &S){
	
	delete[] S.elem;
	S.stacksize=0;
	S.top=-1;
} 


//顺序栈的清空
void ClearStack_Sq(SqStack &S){
	int i;
	ElemType e;
	for(i=S.top;i>=0;i--) Pop_Sq(S,e);
} 


//判断顺序栈是否为空栈 
bool StackEmpty_Sq(SqStack S){
	if(S.top==-1) return TRUE;
	else return FALSE;
}


//顺序栈的插入 
void Push_Sq(SqStack &S,ElemType e){
	if(S.top+1==S.stacksize) Incrementsize_Sq(S);//空间扩容
	S.elem[++S.top]=e;
}//Push_Sq


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



//链栈的基本操作
//初始化 
void InitStack_L(LinkStack &S){
	S=NULL;
}//InitStack_L

//元素入栈 
void Push_L(LinkStack &S,ElemType e){
	LNode *p;
	p=new LNode;
	p->date=e;
	p->next=S;
	S=p;
	
}//Push_L

//栈顶元素出栈 
bool Pop_L(LinkStack &S,ElemType &e){
	if(S==NULL) return FALSE;
	else{
		LNode *p;
		p=S;
		e=p->date;
		S=p->next;
		delete p;	
	}
	
}


