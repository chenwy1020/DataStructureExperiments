//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef char QElemType; 

//��ʽ����
typedef struct LNode{     
	QElemType date;
	struct LNode *next; 
}LNode,*LinkList;

typedef LinkList QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;  

//��������
void InitQueue_L(LinkQueue &Q); 
void DestroyQueue_L(LinkQueue Q);
void EnQueue_L(LinkQueue &Q,QElemType e);
bool DeQueue_L(LinkQueue &Q,QElemType &e);

int main(){
	
	
}

//���г�ʼ�� 
void InitQueue_L(LinkQueue &Q){
	
	Q.front=new LNode;
	Q.rear=Q.front;
	Q.front->next=NULL;
}

//���ٶ��� 
void DestroyQueue_L(LinkQueue Q){
	while(Q.front) {
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
}

//��β������ 
void EnQueue_L(LinkQueue &Q,QElemType e){
	LNode *p;
	p=new LNode;
	p->date = e;
	p->next = NULL;
	Q.rear->next=p;
	Q.rear=p;
}//EnQueue_L

//ɾ�����׽�� 
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


//������� 
void QueueTraverse_L(QueuePtr L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->date<<endl;
		p=p->next;
	}
}
 


