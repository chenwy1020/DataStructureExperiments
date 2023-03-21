//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef char QElemType; 

//链式队列
typedef struct LNode{     
	QElemType date;
	struct LNode *next; 
}LNode,*LinkList;

typedef LinkList QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;  

//函数声明
void InitQueue_L(LinkQueue &Q); 
void DestroyQueue_L(LinkQueue Q);
void EnQueue_L(LinkQueue &Q,QElemType e);
bool DeQueue_L(LinkQueue &Q,QElemType &e);

int main(){
	
	
}

//队列初始化 
void InitQueue_L(LinkQueue &Q){
	
	Q.front=new LNode;
	Q.rear=Q.front;
	Q.front->next=NULL;
}

//销毁队列 
void DestroyQueue_L(LinkQueue Q){
	while(Q.front) {
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
}

//队尾插入结点 
void EnQueue_L(LinkQueue &Q,QElemType e){
	LNode *p;
	p=new LNode;
	p->date = e;
	p->next = NULL;
	Q.rear->next=p;
	Q.rear=p;
}//EnQueue_L

//删除队首结点 
bool DeQueue_L(LinkQueue &Q,QElemType &e){
	LNode *p;
	
	if(Q.front==Q.rear) return FALSE;
	else{
		p=Q.front->next;
		e=p->date;
		Q.front->next=p->next;	
	}

	
	delete p;
	return TRUE; 
}//DeQueue_L


//遍历输出 
void QueueTraverse_L(QueuePtr L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->date<<endl;
		p=p->next;
	}
}
 


