//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef struct LNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	int date;
	struct LNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}LNode,*LinkList;    // LineList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 

//��ʽ��
//����ʽ��ĳ���
int ListLength_L(LinkList L){
	
	//LΪ�����ͷָ�룬����������L ��ָ����ĳ���
	LinkList *p;
	int k=0;
	p=L; 
	while(p) {
		k++;
		p=p->next;
	}
	return k;

} 


//����Ԫ�ز���, ��ʽ��
LNode* locateElem_L(LinkList L,int e){
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


 





















