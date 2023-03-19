//ЁбндсН
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 


typedef LinkList QueuePtr; 
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


void InitQueue_L(LinkQueue Q){
	Q.front=new LNode;
	Q.rear=Q.front;
	Q.front->next=NULL;
}

void DestroyQueue_L(LinkQueue Q){
	while(Q.front) {
	Q.rear=Q.front->next;
	Delete Q.front;
	Q.front=Q.rear;
}
}


void EnQueue_L(LinkQueue Q,QElemType e){
	LNode *p;
	p=new Lnode;
	p->date = e;
	p->next = NULL;
	Q.rear->next=p;
	Q.rear=p;
}

bool DeQueue_L(LinkQueue Q,QElemType e){
	LNode *p;
	
	if(Q.front==Q.rear) return FALSE;
	p=Q.front->next;
	e=p->date;
	Q.front->next=p->next;
	if(p==Q.rear) Q.rear=Q.front;
	delete p;
	return TURE; 
}
