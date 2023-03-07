//������
//10200115 

//#include"stdafx .h"
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

int main(){
	SqList L;
	InitList_Sq(L,100,10);
	L.elem[0]='a';
	L.elem[1]='b';
	L.elem[2]='c';
	L.elem[3]='d';
	L.length=4;
	
	
	printf("%d",LocateElem_Sq(L,'c'));
	
	ListInsert_Sq(L,5,'f');
	
	
}

//˳���Ļ������� 
//��ʼ������ 
void InitList_Sq(SqList &L,int maxsize,int incresize){
	//����һ���������Ϊmaxsize ��˳���L
	
	L.elem = new char[maxsize];//Ϊ˳������һ�������������imaxsize ������ռ�
	
	L.length= 0; //˳����е�ǰ����Ԫ�ظ���Ϊ0
	
	L.listsize= 0; //��˳���������ɵ�maxsize ������Ԫ��
	
	L.incrementsize= incresize; //��Ҫʱ������ incresize ��Ԫ�ؿռ�
	 
}

//����Ԫ�ز���
int LocateElem_Sq(SqList L,char e){
	//��˳���L�в��ҵ�һ����e ��ȵ�����Ԫ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	
	int i; 		//i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
	i= 1; 
	
	char *p;	//p �ĳ�ֵΪ��һ��Ԫ�صĴ洢λ��
	p= L.elem; 
	
	while(i<=L.length && *p++!=e) ++i;
	if(i<=L.length) return i;
	else return 0; 
	
} 

//����Ԫ�ز���
void ListInsert_Sq(SqList &L,int i, char e){
	//��˳���L�ĵ�i ��Ԫ��֮ǰ�����µ�Ԫ�� e,
	//i�ĺϷ�ֵΪ 1<= i <= L.length+1,
	//�������������㣬���ո�˳����Ԥ�������������ݡ�
	
	char *q,*p;
	
	if(i<1 || i>L.length+1) printf("iֵ���Ϸ�");
	
	if(L.length>=L.listsize) increment(L); //��ǰ�洢�ռ�������ΪL���ӷ���L.incrementsize ��Ԫ�ؿռ�
	
	q=&(L.elem[i-1]); //q Ϊ����λ��
	for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p; //����λ�ü��Ժ��Ԫ������
	
	*q=e; //����e
	
	++L.length;
	 
}

//����
void increment(SqList &L){
	char *a;
	int i;
	
	a=new char[L.listsize+L.incrementsize]; //a Ϊ��ʱ���ɵĸ������� 
	
	for(i=0;i<L.length;i++)a[i]=L.elem[i]; //��Ųԭ�ռ�����
	
	delete[] L.elem; //�ͷ�����Ԫ����ռ��ԭ�ռ� L.elem
	
	L.elem = a;		//�ƽ��ռ��׵�ַ
 
	L.listsize+=L.incrementsize;  //���ݺ��˳������ռ� 
	 
	
	
}
 

//ɾ��Ԫ�ز���
void ListDelete_Sq(SqList &L,int i) {
	
}

//���ٽṹ����
void DestroyList_Sq(SqList &L) {
	
}

































































































































































