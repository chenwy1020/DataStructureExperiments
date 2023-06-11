//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 
typedef int ElemType;

//单链表定义 
typedef struct LNode{    //typedef是用来设置结构体别名，使用过后 定义结构体可以 LNode p ;LNode *p;有简化的效果 
	ElemType data;
	struct LNode *next; //结构体自引用-next作为指针 指向 结构体; 
}LNode,*LinkList;    // LinkList 是通过结构体声明的指针变量（结构体指针），相当于LNode *LinkList;  LinkList是指向该种结构体的指针 
//LNode本身就是一个结构体，但是它的命名是一个指针类型。 

//单链表基本操作 

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
	cout<<"单链表输出:";
	ListTraverse_L(L);
	
	cout<<"长度："<<ListLength_L(L)<<endl;
	
	p=LocateElem_L(L,1);
	cout<<"获取数据为1的结点，它的数据为:"<<p->data<<endl;
	//printf("1");
	
	
	s=new LNode;//给一个新结点分配内存，并返回其地址给 s ,s是一个储存了结构体地址的指针变量,而这个结构体名本身就是一个指针
				//举例，s房间簿, *s 指向是房间名，房间名本身也是一个指针，它指向房间内部的东西 
				//new命令 建造了一间新房子，并把这个的地址返回房间簿，
	(*s).data=0;//等价于s->data=0; 
	LinkInsert_L(L,p,s);
	cout<<"插入结点后，单链表输出:";
	ListTraverse_L(L);
	cout<<"长度："<<ListLength_L(L)<<endl;
	
	q=LocateElem_L(L,2);
	cout<<"获取数据为2的结点，它的数据为:"<<q->data<<endl;
	ListDelete_L(L,q);
	cout<<"删除结点后，单链表输出:";
	ListTraverse_L(L);
	cout<<"长度："<<ListLength_L(L)<<endl;
	
	//--------------------------------------------------
	
	cout<<"单链表输出:"<<endl;
	ListTraverse_L(L);	
	ListTraverse_L(V);
	ListConcat(L,V,W); 
	cout<<"单链表拼接结果：";
	ListTraverse_L(W);
	
	
	//--------------------------------------------------
	cout<<"单链表输出:";
	ListTraverse_L(V);
	DelBet(V,2,6);
	cout<<"删除条件元素后的结果"; 
	ListTraverse_L(V);
	
	delete s;		
	
}

//线性表基本操作 
//求线性表的长度
int ListLength_L(LinkList L){
	//L为链表的头指针，本函数返回L 所指链表的长度
	LinkList p;
	int i=0;
	p=L; 
	while(p){
		i++;
		p=p->next;
	}
	return i;	
} 

//查找元素
LinkList LocateElem_L(LinkList L,ElemType e){
	LinkList p;
	p=L;
	while(p && p->data!=e) p=p->next;
	
	return p;
}

//插入结点操作
void LinkInsert_L(LinkList &L,LNode *p,LNode *s){
	//将 s 插入到 p前 
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

//删除结点操作
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

//创建单链表 
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

//单链表的拼接
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

//递增序列 删除表中所有值大于mink且小于mark的元素
void DelBet(LinkList &L, int mink ,int maxk ){
	LNode  *p,*q;
   	p=L->next; q=L;
    if( p->data>=maxk)
        cout<<"不存在大于"<<mink<<"并且小于"<<maxk<<"的元素"<<endl;
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


//遍历输出 
void ListTraverse_L(LinkList L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


