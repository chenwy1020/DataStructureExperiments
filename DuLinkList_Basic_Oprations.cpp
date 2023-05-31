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

//双向链表定义 
typedef struct DuLNode{    //typedef是用来设置结构体别名，使用过后 定义结构体可以 LNode p ;LNode *p;有简化的效果 
	ElemType date;
	struct DuLNode *prior; 
	struct DuLNode *next; //结构体自引用-next作为指针 指向 结构体; 
}DuLNode,*DuLinkList;    // LinkList 是通过结构体声明的指针变量（结构体指针），相当于LNode *LinkList;  LinkList是指向该种结构体的指针 
//LNode本身就是一个结构体，但是它的命名是一个指针类型。 


//函数声明
void CreateList_DuL(DuLinkList &L,ElemType *A,int n);
int ListLength_DuL(DuLinkList L);
DuLinkList LocateElem_DuL(DuLinkList L,ElemType e);
void ListInsert_DuL(DuLinkList &L,DuLNode *p,DuLNode *s);
void ListDelete_DuL(DuLinkList &L,DuLNode *p,ElemType &e);
void ListTraverse_DuL(DuLinkList L); 

int main(){
	ElemType A[4]={1,2,3,4};
	ElemType e;
	DuLinkList L,p,s,q;

	//printf("1");
	CreateList_DuL(L,A,4);
	//printf("2");
	cout<<"双向循环链表输出:";
	ListTraverse_DuL(L);
	
	cout<<"长度："<<ListLength_DuL(L)<<endl;
	
	p=LocateElem_DuL(L,1);
	cout<<"获取数据为1的结点，它的数据为:"<<p->date<<endl;
	//printf("1");
	
	
	s=new DuLNode;//给一个新结点分配内存，并返回其地址给 s ,s是一个储存了结构体地址的指针变量,而这个结构体名本身就是一个指针
				//举例，s房间簿, *s 指向是房间名，房间名本身也是一个指针，它指向房间内部的东西 
				//new命令 建造了一间新房子，并把这个的地址返回房间簿，
	s->date=0; //等价于(*s).date=0;
	ListInsert_DuL(L,p,s);
	cout<<"插入结点后，双向循环链表输出:";
	ListTraverse_DuL(L);
	cout<<"长度："<<ListLength_DuL(L)<<endl;
	
	
	q=LocateElem_DuL(L,2);
	//printf("陈文宇"); 
	cout<<"获取数据为2的结点，它的数据为:"<<q->date<<endl;
	//printf("陈文宇"); 
	ListDelete_DuL(L,q,e);
	cout<<"删除结点后，双向循环链表输出:";
	ListTraverse_DuL(L);
	cout<<"长度："<<ListLength_DuL(L)<<endl;
	
	delete s;
}


//创建双向循环链表 
void CreateList_DuL(DuLinkList &L,ElemType *A,int n){

	DuLNode *s;	
	
	//初始化 
	L=new DuLNode;
	L->prior=L; 
	L->next=L;
	
	//赋值 
	for(int i=n-1;i>=0;--i){
		s=new DuLNode;
		s->date=A[i];
		s->prior=L->prior;
		L->prior->next=s;
		s->next=L;
		L->prior=s;
		L=s;
		
	}
}

//求双向循环链表的长度
int ListLength_DuL(DuLinkList L){
	//L为链表的头指针，本函数返回L 所指链表的长度
	DuLinkList p;
	int i=0;
	p=L; 
	while(p->next != L){
		i++;
		p=p->next;
	}
	return i;	
} 

//查找元素
DuLinkList LocateElem_DuL(DuLinkList L,ElemType e){
	DuLNode* p;
	p=L;
	while(p->next!=L && p->date!=e) p=p->next;
	if(p->next==L) cout<<"无该结点"<<endl; 
	else return p;
}

//插入 
void ListInsert_DuL(DuLinkList &L,DuLNode *p,DuLNode *s){
	//在带头结点的双向循环链表L中p结点之前插入s结点 
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

//删除结点 
void ListDelete_DuL(DuLinkList &L,DuLNode *p,ElemType &e){
	//删除带头结点的双向循环列表L中的p结点，并以e 返回它的数据元素
	e=p->date;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
}//ListDelete_DuL

//遍历输出 
void ListTraverse_DuL(DuLinkList L){
	DuLNode *p;
	p=L;
	while(p->next !=L ){
		cout<<p->date<<" ";
		p=p->next;
	}
	cout<<endl;
}



