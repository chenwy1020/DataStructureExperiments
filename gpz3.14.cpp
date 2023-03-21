#include<iostream>
using namespace std;
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;

void CreateList_L(LinkList &L,int A[],int n){
	L=NULL;
	int i;Lnode *s;
	for(i=n-1;i>=0;i--){
		s=new Lnode;
		s->data=A[i];
		s->next=L;
		L=s;
	}
}

int ListLength_L(LinkList L){
	Lnode *p;
	p=L;int k=0;
	while(p){
		k++;
		p=p->next;
	}
	return k;
}

void ListTraverse_L(LinkList L){
	Lnode *p;
	p=L;
	while(p){
		cout<<p->data<<endl;
		p=p->next;
	}
}

Lnode* LocateElem_L(LinkList L,int e){
	Lnode *p;
	p=L;
	while(p&&p->data!=e) p=p->next;
	return p;	
}
void ListInsert_next_L(LinkList &L,Lnode *p,Lnode *s){
	s->next=p->next;
	p->next=s;
	}
void ListInsert_prior_L(LinkList &L,Lnode *p,Lnode *s){
	Lnode *q;
	if(p==L){
		s->next=L;L=s; 
	}
	else{
		q=L;
		while(q->next!=p) q=q->next;
		q->next=s; s->next=p;
	}
}

void ListDelete_L(LinkList &L,Lnode *p){
	Lnode *q;
	if(p==L){
		L=p->next;
	}
	else{
		q=L;
		while(q->next!=p) 
		q=q->next;q->next=p->next;
	}
	delete p;
}	
int main(){
	int m;
	int A[]={1,2,3,4,5,6};
	LinkList Link;
	CreateList_L(Link,A,6);
	cout<<"创建的单链表结点值"<<endl;
	ListTraverse_L(Link);
	Lnode *s,*p,*q,*r;
	s=new Lnode;
	s->data=10;
	q=new Lnode;
	q->data=12;
	p=LocateElem_L(Link,2);
	r=LocateElem_L(Link,5);
	cout<<"后插入结点操作"<<endl;
	ListInsert_next_L(Link,p,s);
	ListTraverse_L(Link);
	cout<<"前插入结点操作"<<endl;
	ListInsert_prior_L(Link,r,q);
	ListTraverse_L(Link); 
	cout<<"删除结点操作"<<endl;
	ListDelete_L(Link,r);
	ListTraverse_L(Link); 
	return 0;
}


