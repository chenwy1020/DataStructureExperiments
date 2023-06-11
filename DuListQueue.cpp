//陈文宇
//10200115
#include<iostream>
using namespace std; 

typedef int QElemType;
typedef struct QNode {   
	QElemType data;
    struct QNode *next;
} LNode, *QueuePtr;   // 结点类型
typedef struct{
    QueuePtr  rear;   // 队尾指针
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
	cout<<"出队列前为："; 
	ListTraverse_L(Q);
	DeCQueue(Q,e);
	cout<<"出队列后为："; 
	ListTraverse_L(Q);
}


void InitCQueue(CLinkQueue &Q){  
	//初始化循环链表表示的队列Q
	Q.rear = new LNode;
    Q.rear->next=Q.rear;
 } //InitCQueue 

//入队列 
void EnCQueue(CLinkQueue &Q, QElemType e){
	QueuePtr p;
	p=new LNode;
    p->data = e;
    p->next=Q.rear->next;
    Q.rear->next=p;
}//EnCQueue

//出队列 
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

//遍历输出 
void ListTraverse_L(CLinkQueue L){
	QueuePtr p;
	p=L.rear->next;
	while(p != L.rear){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}//ListTraverse_L

