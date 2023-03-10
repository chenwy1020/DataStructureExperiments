//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef struct LNode{    //typedef是用来设置结构体别名，使用过后 定义结构体可以 LNode p ;LNode *p;有简化的效果 
	int date;
	struct LNode *next; //结构体自引用-next作为指针 指向 结构体; 
}LNode,*LinkList;    // LineList 是通过结构体声明的指针变量（结构体指针），相当于LNode *LinkList;  LinkList是指向该种结构体的指针 

//链式表
//求链式表的长度
int ListLength_L(LinkList L){
	
	//L为链表的头指针，本函数返回L 所指链表的长度
	LinkList *p;
	int k=0;
	p=L; 
	while(p) {
		k++;
		p=p->next;
	}
	return k;

} 


//查找元素操作, 链式表
LNode* locateElem_L(LinkList L,int e){
	//在L所指的链式表中找找第一个和e 相等的数据元素，
	//若存在，则返回它在链式表中的位置，
	//即指向该元素所在结点的指针
	LNode *p;
	p=L;
	while(p && p->date != e) p=p->next;
	return p; 
	
} 


//插入结点操作
void ListInsert_L(LinkList &L,LNode *p,LNode *s){
	//指针p指向 L 为头指针的链式表中某个结点，将s 插入到 p 结点之前
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


 





















