//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 
typedef int ElemType;

//�������� 
typedef struct LNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	ElemType date;
	struct LNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}LNode,*LinkList;    // LinkList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 
//LNode�������һ���ṹ�壬��������������һ��ָ�����͡� 

//������������� 

int ListLength_L(LinkList L);
LNode* LocateElem_L(LinkList L,ElemType e);
void LinkInsert_L(LinkList &L,LNode *p,LNode *s);
void ListDelete_L(LinkList L,LNode *p);
void CreateList_L(LinkList &L,ElemType *A,int n);
void ListTraverse_L(LinkList L); 

int main(){
	ElemType A[3]={1,2,3};
	LinkList L,p,s,q;
	L=NULL;
	//printf("1");
	
	CreateList_L(L,A,3);
	//printf("2");
	cout<<"���������:"<<endl;
	ListTraverse_L(L);
	
	cout<<"���ȣ�"<<ListLength_L(L)<<endl;
	
	p=LocateElem_L(L,1);
	cout<<"��ȡ����Ϊ1�Ľ�㣬��������Ϊ:"<<p->date<<endl;
	//printf("1");
	
	
	s=new LNode;//��һ���½������ڴ棬���������ַ�� s ,s��һ�������˽ṹ���ַ��ָ�����,������ṹ�����������һ��ָ��
				//������s���䲾, *s ָ���Ƿ�����������������Ҳ��һ��ָ�룬��ָ�򷿼��ڲ��Ķ��� 
				//new���� ������һ���·��ӣ���������ĵ�ַ���ط��䲾��
	(*s).date=0;//�ȼ���s->date=0; 
	LinkInsert_L(L,p,s);
	cout<<"������󣬵��������:"<<endl;
	ListTraverse_L(L);
	cout<<"���ȣ�"<<ListLength_L(L)<<endl;
	
	
	q=LocateElem_L(L,2);
	//printf("������"); 
	cout<<"��ȡ����Ϊ2�Ľ�㣬��������Ϊ:"<<q->date<<endl;
	//printf("������"); 
	ListDelete_L(L,q);
	cout<<"ɾ�����󣬵��������:"<<endl;
	ListTraverse_L(L);
	delete s;
}

//���Ա�������� 
//�����Ա�ĳ���
int ListLength_L(LinkList L){
	//LΪ�����ͷָ�룬����������L ��ָ����ĳ���
	LinkList p;
	int i=0;
	p=L; 
	while(p){
		i++;
		p=p->next;
	}
	return i;	
} 

//����Ԫ��
LinkList LocateElem_L(LinkList L,ElemType e){
	LinkList p;
	p=L;
	while(p && p->date!=e) p=p->next;
	
	return p;
}

//���������
void LinkInsert_L(LinkList &L,LNode *p,LNode *s){
	//�� s ���뵽 pǰ 
	LNode *q;
	
	if(p==L){
		s->next=p;
		L=s;
	}
	else {
		q=L;
		while(q->next != p) q=q->next;
		s->next=p;
		q->next=s;
	}	
} 

//ɾ��������
void ListDelete_L(LinkList L,LNode *p){
	LNode *q;
	if(p==L){
		L=p->next;
	}
	else{
		q=L;
		while(q->next!=p) q=q->next;
		q->next=p->next;
	}
	delete p;
}


//���������� 
void CreateList_L(LinkList &L,ElemType *A,int n){
	int i;
	LNode *s;
	/*
	L = NULL;
	s->date=A[n-1];
	s->next=L;
	L=s;
	*/
	
	
	for(i=n-1;i>=0;--i){
		s=new LNode;
		s->date=A[i];
		//printf("3");
		s->next=L;
		L=s; 

	}
}


//������� 
void ListTraverse_L(LinkList L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->date<<endl;
		p=p->next;
	}
}

















































































