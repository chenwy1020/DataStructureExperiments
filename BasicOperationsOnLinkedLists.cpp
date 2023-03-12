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
//������ 
typedef struct LNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	ElemType date;
	struct LNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}LNode,*LinkList;    // LineList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 

//˫���� 
typedef struct DuLNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	ElemType date;
	struct DuLNode *prior;
	struct DuLNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}DuLNode,*DuLinkList;  

int ListLength_L(LinkList L); 
LNode* locateElem_L(LinkList L,ElemType e);
void ListInsert_L(LinkList &L,LNode *p,LNode *s);
ElemType ListDelete_L(LinkList &L,LNode *p,ElemType &e);


int main(){
	
}


//��ʽ��
//����ʽ��ĳ���
int ListLength_L(LinkList L){
	
	//LΪ�����ͷָ�룬����������L ��ָ����ĳ���
	LNode *p;
	int k=0;
	p=L; 
	while(p) {
		k++;
		p=p->next;
	}
	return k;

} 


//����Ԫ�ز���, ��ʽ��
LNode* locateElem_L(LinkList L,ElemType e){
	//��L��ָ����ʽ�������ҵ�һ����e ��ȵ�����Ԫ�أ�
	//�����ڣ��򷵻�������ʽ���е�λ�ã�
	//��ָ���Ԫ�����ڽ���ָ��
	LNode *p;
	p=L;
	while(p && p->date != e) p=p->next;
	return p; 
	
} 


//���������
void ListInsert_L(LinkList &L,LNode *p,LNode *s){
	//ָ��pָ�� L Ϊͷָ�����ʽ����ĳ����㣬��s ���뵽 p ���֮ǰ
	LNode *q;
	
	if(p==L) {
		s->next= L;
		L=s;
	} 
	else{
		q=L;
		while(q->next != p) q=q->next;
		q->next=s;
		s->next=p;
	}
	
} 

//ɾ�����
ElemType ListDelete_L(LinkList &L,LNode *p,ElemType &e){
	//pָ����LΪͷָ��������ĳһ���
	//e���� ��ɾ���Ľ��������� 
	LNode *q;
	q=L;
	if(p==L) L=p->next;
	else{
		while(p!=q->next)q=q->next;//����ǰ�� 
		q->next=p->next;
	}
	e=p->date;
	delete p;
	return e;
} 

//���򴴽�������
void CreateList_L(LinkList &L,ElemType *A,int n){
	L=NULL;
	int i;
	LNode *p;

	for(i=n-1;i>-1;i--){
		p=new LNode;
		p->date=A[i];
		p->next=L;
		L=p; 
	}
} 
 

//����
void InvertLinkedList(LinkList &L){
	LNode *p,*q;
	p=L;
	L=NULL;
	while(p){
		q=p;
		q->next=L;
		L=q;
		p=p->next;
	}
} 

 
//




















