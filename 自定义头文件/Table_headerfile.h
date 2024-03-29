//陈文宇
//10200115 

#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef struct {
	char *elem;
	int length;
	int listsize;
	int incrementsize;
}SqList;


void InitList_Sq(SqList &L,int maxsize,int incresize);
int LocateElem_Sq(SqList L,char e);
void ListInsert_Sq(SqList &L,int i, char e);
void increment(SqList &L); 
void ListDelete_Sq(SqList &L,int i,char &e);
void DestroyList_Sq(SqList &L);
void invert(char *R,int s,int t);
void ListTraverse_Sq(SqList L); 


//顺序表的基本操作 
//初始化操作 
void InitList_Sq(SqList &L,int maxsize,int incresize){
	//构造一个最大容量为maxsize 的顺序表L
	
	L.elem = new char[maxsize];//为顺序表分配一个最大容量嗯我imaxsize 的数组空间
	
	L.length= 0; //顺序表中当前所含元素个数为0
	
	L.listsize= maxsize; //该顺序表可以容纳的maxsize 个数据元素
	
	L.incrementsize= incresize; //需要时可扩容 incresize 个元素空间
	 
}

//查找元素操作
int LocateElem_Sq(SqList L,char e){
	//在顺序表L中查找第一个与e 相等的数据元素
	//若找到，则返回其在L中的位序，否则返回0
	
	int i; 		//i的初值为第一个元素的位序
	i= 1; 
	
	char *p;	//p 的初值为第一个元素的存储位置
	p= L.elem; 
	
	while(i<=L.length && *p++!=e) ++i;
	if(i<=L.length) return i;
	else return 0; 
	
} 

//插入元素操作
void ListInsert_Sq(SqList &L,int i, char e){
	//在顺序表L的第i 个元素之前插入新的元素 e,
	//i的合法值为 1<= i <= L.length+1,
	//若表中容量不足，则按照该顺序表的预定义来增量扩容、
	if(i<1 || i>L.length+1) printf("i值不合法");
	
	else {
			char *q,*p;
			if(L.length>=L.listsize) increment(L); //当前存储空间已满，为L增加分配L.incrementsize 个元素空间
	
			q=&(L.elem[i-1]); //q 为插入位置
			for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p; //插入位置及以后的元素右移
	
			*q=e; //插入e
	
			++L.length;		
	}
	 
}

//扩容
void increment(SqList &L){
	char *a;
	int i;
	
	a=new char[L.listsize+L.incrementsize]; //a 为临时过渡的辅助数组 
	
	for(i=0;i<L.length;i++)a[i]=L.elem[i]; //腾挪原空间数据
	
	delete[] L.elem; //释放数据元素所占的原空间 L.elem
	
	L.elem = a;		//移交空间首地址
 
	L.listsize+=L.incrementsize;  //扩容后的顺序表最大空间 
	
}
 

//删除元素操作
void ListDelete_Sq(SqList &L,int i,char &e){
	char *p;
	char *q;
	
	if( i< 1 || i>L.length) printf("i值不合法");
	
	p= &(L.elem[i-1]);
	q= &(L.elem[L.length-1]);
	
	for(++p; p<= q; ++p) *(p-1) = *p;
	
	--L.length;
	
}

//销毁结构操作
void DestroyList_Sq(SqList &L){
	
	delete[] L.elem;
	L.listsize=0;
	L.length=0;
	
}


//逆置
void invert(char *R,int s,int t){
	
	//本算法将数组 R 中下标 自 t 到 s 的元素逆置
	int k;
	char w;
	
	for(k= s; k<= (s+ t)/2.0; k++ ){
		w=R[k];
		R[k]= R[t+s-k];
		R[t+s-k]=w;	
	}  
	
} 


//输出 
void ListTraverse_Sq(SqList L){
	int i;
	for(i=0;i<L.length;i++){
		
		printf("%c    ",L.elem[i]);
	}
	printf("\n");
	
}


//重置为空表
void ClearList_Sq(SqList &L){

	int i;
	for(i=0; i<L.length; i++)
		L.elem[i]='\0';	
	
} 

//判断是否为空表
bool ListEmpty(SqList L){

	if(L.elem[0]!='\0')
			return TRUE;
	else
		return FALSE; 
} 


//获取表长
int ListLength_Sq(SqList L){
	
	int i=0;
	while(L.elem[i++]!='\0');
	L.length=i;
	
} 
 

//获取第 i 个元素
char GetElem_Sq(SqList L,int i, char e){
	if(i<1 || i>L.length) printf("i值不合法"); 
	else {
		e = L.elem[i-1];
		return e;
	}
}
 
//获取前驱
char PriorElem_Sq(SqList L,char cur_e,char &pre_e){
	
	int i=0;
	
	while(L.elem[i++]!=cur_e && i<=L.length);
	if(i==1 || i==L.length+1) printf("cer_e没有前驱");
	else {
		pre_e=L.elem[i-2];
		return pre_e;
	}
}


//获取后继 
char NextElem_Sq(SqList L,char cur_e,char &next_e){
	int i=0;
	
	while(L.elem[i++]!=cur_e && i<=L.length-1);
	if(i==L.length) printf("cer_e没有后继");
	else {
		next_e=L.elem[i];
		return next_e;
	}
}






