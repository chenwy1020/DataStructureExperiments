//������
//10200115
#include<iostream>
using namespace std; 

typedef int QElemType;
typedef struct QNode {   
	QElemType data;
    struct QNode *next;
} LNode, *QueuePtr;   // �������
typedef struct{
    QueuePtr  rear;   // ��βָ��
}CLinkQueue;


void InitCQueue(CLinkQueue &Q);
void EnCQueue(CLinkQueue &Q, QElemType  e);
bool DeCQueue(CLinkQueue &Q , QElemType &e); 
void ListTraverse_L(CLinkQueue L);

int main(){
	CLinkQueue Q;
	QElemType e; 
	
	InitCQueue(Q);
	
	EnCQueue(Q,1);	
	EnCQueue(Q,2);
	EnCQueue(Q,3);
	EnCQueue(Q,4);
	cout<<"������ǰΪ��"; 
	ListTraverse_L(Q);
	DeCQueue(Q,e);
	cout<<"�����к�Ϊ��"; 
	ListTraverse_L(Q);
}


void InitCQueue(CLinkQueue &Q){  
	//��ʼ��ѭ�������ʾ�Ķ���Q
	Q.rear = new LNode;
    Q.rear->next=Q.rear;
 } //InitCQueue 

//����� 
void EnCQueue(CLinkQueue &Q, QElemType e){
	QueuePtr p;
	p=new LNode;
    p->data = e;
    p->next=Q.rear->next;
    Q.rear->next=p;
}//EnCQueue

//������ 
bool  DeCQueue(CLinkQueue &Q , QElemType &e){
    QueuePtr p,q;
    if (Q.rear->next == Q.rear)
        return false;
    while(p->next!=Q.rear){
    	q=p;
    	p=p->next;
	}
    e = p->data;
    q->next=Q.rear;
    delete p;
 
}//DeCQueue

//������� 
void ListTraverse_L(CLinkQueue L){
	QueuePtr p;
	p=L.rear->next;
	while(p != L.rear){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}//ListTraverse_L

