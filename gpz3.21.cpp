#include<iostream>
using namespace std;
typedef struct DuLNode{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

void ListInsert_DuL(DuLinkList &L,DuLNode *p,DuLNode *s){
	s->prior=p->prior;   p->prior->next=s;
	s->next=p;  p->prior=s;
}

void ListDelete_DuL(DuLinkList &L,DuLNode *p,int e){
	
	e=p->data;                                    
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;                             
}                

void CreateList_L(DuLinkList &L,int A[],int n){
	DuLNode *s,*r;int i;
	L=new DuLNode;
	L->next=L;L->prior=L;r=L;
	for(i=0;i<=n-1;i++){
		s=new DuLNode;
		s->data=A[i];
		s->prior=r;
		r->next=s;
		s->next=L;
		r=s;
		L->prior=s;
	}
}

void ListTraverse_L(DuLinkList L){
	DuLNode *p;
	p=L;
	while(p->next!=L){		
	p=p->next;
		cout<<p->data<<endl;

	}
}

DuLNode* LocateElem_L(DuLinkList L,int e){
	DuLNode *p;
	p=L;
	while(p&&p->data!=e) p=p->next;
	return p;	
}

int main(){
	int A[]={1,2,3,4,5,6};
	int a;
	DuLNode *r,*p,*s;
	s=new DuLNode;
	s->data=10;
	DuLinkList Link;
	CreateList_L(Link,A,6);
	cout<<"创建的单链表结点值"<<endl;
	ListTraverse_L(Link);
	r=LocateElem_L(Link,5);
	p=LocateElem_L(Link,2);
	cout<<"插入结点操作后"<<endl;
	ListInsert_DuL(Link,p,s);
	ListTraverse_L(Link);
	ListDelete_DuL(Link,r,a);
	cout<<"删除结点操作后"<<endl;
	ListTraverse_L(Link);
	
}
