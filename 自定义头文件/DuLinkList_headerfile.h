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


//˫�������� 
typedef struct DuLNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	ElemType date;
	struct DuLNode *prior; 
	struct DuLNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}DuLNode,*DuLinkList;    // LinkList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 
//LNode�������һ���ṹ�壬��������������һ��ָ�����͡� 


//��������
void CreateList_DuL(DuLinkList &L,ElemType *A,int n);
int ListLength_DuL(DuLinkList L);
DuLinkList LocateElem_DuL(DuLinkList L,ElemType e);
void ListInsert_DuL(DuLinkList &L,DuLNode *p,DuLNode *s);
void ListDelete_DuL(DuLinkList &L,DuLNode *p,ElemType &e);
void ListTraverse_DuL(DuLinkList L); 


//����˫��ѭ������ 
void CreateList_DuL(DuLinkList &L,ElemType *A,int n){
	int i;
	DuLNode *s;	
	L->prior=L;
	L->next=L;
	
	for(i=n-1;i>=0;--i){
		s=new DuLNode;
		s->date=A[i];
		//printf("3");
		s->prior=L->prior;
		L->prior->next=s;
		s->next=L;
		L->prior=s;
		L=s;
		
	}
}


//��˫��ѭ������ĳ���
int ListLength_DuL(DuLinkList L){
	//LΪ�����ͷָ�룬����������L ��ָ����ĳ���
	DuLinkList p;
	int i=0;
	p=L; 
	while(p->next != L){
		i++;
		p=p->next;
	}
	return i;	
} 


//����Ԫ��
DuLinkList LocateElem_DuL(DuLinkList L,ElemType e){
	DuLinkList p;
	p=L;
	while(p->next!=L && p->date!=e) p=p->next;
	if(p->next==L) cout<<"�޸ý��"<<endl; 
	else return p;
}

//���� 
void ListInsert_DuL(DuLinkList &L,DuLNode *p,DuLNode *s){
	//�ڴ�ͷ����˫��ѭ������L��p���֮ǰ����s��� 
	if(p!=L){
		s->prior=p->prior;
		p->prior->next=s;
		s->next=p;
		p->prior=s;
	} 
	else{		
		s->prior=p->prior;
		p->prior->next=s;
		s->next=p;
		p->prior=s;
		L=s;		
	}

	
}//ListInsert_DuL

//ɾ����� 
void ListDelete_DuL(DuLinkList &L,DuLNode *p,ElemType &e){
	//ɾ����ͷ����˫��ѭ���б�L�е�p��㣬����e ������������Ԫ��
	e=p->date;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
}//ListDelete_DuL

//������� 
void ListTraverse_DuL(DuLinkList L){
	DuLNode *p;
	p=L;
	while(p->next !=L ){
		cout<<p->date<<endl;
		p=p->next;
	}
}


























