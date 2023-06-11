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
	ElemType data;
	struct LNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}LNode,*LinkList;    // LinkList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 
//LNode�������һ���ṹ�壬��������������һ��ָ�����͡� 

//������������� 

int ListLength_L(LinkList L);
LNode* LocateElem_L(LinkList L,ElemType e);
void LinkInsert_L(LinkList &L,LNode *p,LNode *s);
void ListDelete_L(LinkList L,LNode *p);
void CreateList_L(LinkList &L,ElemType *A,int n);
void ListConcat(LinkList &ha,LinkList &hb,LinkList &hc);
void ListTraverse_L(LinkList L); 
void DelBet(LinkList &L, int mink ,int maxk );


int main(){
	ElemType A[3]={1,2,3},B[7]={1,2,3,4,5,6,7};
	LinkList L,p,s,q,V,W;
	L=NULL;
	V=NULL;
	W=new LNode;
	//printf("1");
	
	CreateList_L(L,A,3);
	CreateList_L(V,B,7);
	//printf("2");
	cout<<"���������:";
	ListTraverse_L(L);
	
	cout<<"���ȣ�"<<ListLength_L(L)<<endl;
	
	p=LocateElem_L(L,1);
	cout<<"��ȡ����Ϊ1�Ľ�㣬��������Ϊ:"<<p->data<<endl;
	//printf("1");
	
	
	s=new LNode;//��һ���½������ڴ棬���������ַ�� s ,s��һ�������˽ṹ���ַ��ָ�����,������ṹ�����������һ��ָ��
				//������s���䲾, *s ָ���Ƿ�����������������Ҳ��һ��ָ�룬��ָ�򷿼��ڲ��Ķ��� 
				//new���� ������һ���·��ӣ���������ĵ�ַ���ط��䲾��
	(*s).data=0;//�ȼ���s->data=0; 
	LinkInsert_L(L,p,s);
	cout<<"������󣬵��������:";
	ListTraverse_L(L);
	cout<<"���ȣ�"<<ListLength_L(L)<<endl;
	
	q=LocateElem_L(L,2);
	cout<<"��ȡ����Ϊ2�Ľ�㣬��������Ϊ:"<<q->data<<endl;
	ListDelete_L(L,q);
	cout<<"ɾ�����󣬵��������:";
	ListTraverse_L(L);
	cout<<"���ȣ�"<<ListLength_L(L)<<endl;
	
	//--------------------------------------------------
	
	cout<<"���������:"<<endl;
	ListTraverse_L(L);	
	ListTraverse_L(V);
	ListConcat(L,V,W); 
	cout<<"������ƴ�ӽ����";
	ListTraverse_L(W);
	
	
	//--------------------------------------------------
	cout<<"���������:";
	ListTraverse_L(V);
	DelBet(V,2,6);
	cout<<"ɾ������Ԫ�غ�Ľ��"; 
	ListTraverse_L(V);
	
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
	while(p && p->data!=e) p=p->next;
	
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
	L = NULL;
	for(i=n-1;i>=0;--i){
		s=new LNode;
		s->data=A[i];
		s->next=L;
		L=s; 
	}
}

//�������ƴ��
void ListConcat(LinkList &ha,LinkList &hb,LinkList &hc){
    
    LNode *pa,*pb;
    int m,n;
    m=ListLength_L(ha); 
	n=ListLength_L(hb);
    if(m<=n){  
		pa=ha->next; 
        while(pa->next) pa=pa->next;
        hc=ha;   
		pa->next=hb;
    }
    else {
    	pb=hb->next;
        while(pb->next) pb=pb->next;
        hc=hb;   
		pb->next=ha;
    } //if
    
}//ListConcat

//�������� ɾ����������ֵ����mink��С��mark��Ԫ��
void DelBet(LinkList &L, int mink ,int maxk ){
	LNode  *p,*q;
   	p=L->next; q=L;
    if( p->data>=maxk)
        cout<<"�����ڴ���"<<mink<<"����С��"<<maxk<<"��Ԫ��"<<endl;
    else  {  
		while(p && p->data<=mink){   
			q=p;  
			p=p->next;  
		}
        while(p && p->data<maxk){   
			q->next=p->next; 
            delete p;
            p=q->next;
        }
    }//else
}//Delete_Between 


//������� 
void ListTraverse_L(LinkList L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


