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
	ElemType date;
	struct LNode *next; //结构体自引用-next作为指针 指向 结构体; 
}LNode,*LinkList;    // LinkList 是通过结构体声明的指针变量（结构体指针），相当于LNode *LinkList;  LinkList是指向该种结构体的指针 
//LNode本身就是一个结构体，但是它的命名是一个指针类型。 

//单链表基本操作 

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
	cout<<"单链表输出:"<<endl;
	ListTraverse_L(L);
	
	cout<<"长度："<<ListLength_L(L)<<endl;
	
	p=LocateElem_L(L,1);
	cout<<"获取数据为1的结点，它的数据为:"<<p->date<<endl;
	//printf("1");
	
	
	s=new LNode;//给一个新结点分配内存，并返回其地址给 s ,s是一个储存了结构体地址的指针变量,而这个结构体名本身就是一个指针
				//举例，s房间簿, *s 指向是房间名，房间名本身也是一个指针，它指向房间内部的东西 
				//new命令 建造了一间新房子，并把这个的地址返回房间簿，
	(*s).date=0;//等价于s->date=0; 
	LinkInsert_L(L,p,s);
	cout<<"插入结点后，单链表输出:"<<endl;
	ListTraverse_L(L);
	cout<<"长度："<<ListLength_L(L)<<endl;
	
	
	q=LocateElem_L(L,2);
	//printf("陈文宇"); 
	cout<<"获取数据为2的结点，它的数据为:"<<q->date<<endl;
	//printf("陈文宇"); 
	ListDelete_L(L,q);
	cout<<"删除结点后，单链表输出:"<<endl;
	ListTraverse_L(L);
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
	while(p && p->date!=e) p=p->next;
	
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


//遍历输出 
void ListTraverse_L(LinkList L){
	LNode *p;
	p=L;
	while(p){
		cout<<p->date<<endl;
		p=p->next;
	}
}

















































































