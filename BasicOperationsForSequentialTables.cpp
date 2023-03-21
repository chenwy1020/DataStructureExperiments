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
void ListDelete_Sq(SqList &L,int i,char &e);
void DestroyList_Sq(SqList &L);
void invert(char *R,int s,int t);
void ListTraverse_Sq(SqList L); 

int main(){
	SqList L;
	InitList_Sq(L,100,10);
	L.elem[0]='a';
	L.elem[1]='b';
	L.elem[2]='c';
	L.elem[3]='d';
	L.length=4;
	
	ListTraverse_Sq(L);
	
	printf("%d\n",LocateElem_Sq(L,'c'));
	
	ListInsert_Sq(L,5,'f');
	
	ListTraverse_Sq(L); 
	
	invert(L.elem,0,4);
	ListTraverse_Sq(L); 
	
}

//˳���Ļ������� 
//��ʼ������ 
void InitList_Sq(SqList &L,int maxsize,int incresize){
	//����һ���������Ϊmaxsize ��˳���L
	
	L.elem = new char[maxsize];//Ϊ˳������һ�������������imaxsize ������ռ�
	
	L.length= 0; //˳����е�ǰ����Ԫ�ظ���Ϊ0
	
	L.listsize= maxsize; //��˳���������ɵ�maxsize ������Ԫ��
	
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
	if(i<1 || i>L.length+1) printf("iֵ���Ϸ�");
	
	else {
			char *q,*p;
			if(L.length>=L.listsize) increment(L); //��ǰ�洢�ռ�������ΪL���ӷ���L.incrementsize ��Ԫ�ؿռ�
	
			q=&(L.elem[i-1]); //q Ϊ����λ��
			for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p; //����λ�ü��Ժ��Ԫ������
	
			*q=e; //����e
	
			++L.length;		
	}
	 
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
void ListDelete_Sq(SqList &L,int i,char &e){
	char *p;
	char *q;
	
	if( i< 1 || i>L.length) printf("iֵ���Ϸ�");
	
	p= &(L.elem[i-1]);
	q= &(L.elem[L.length-1]);
	
	for(++p; p<= q; ++p) *(p-1) = *p;
	
	--L.length;
	
}

//���ٽṹ����
void DestroyList_Sq(SqList &L){
	
	delete[] L.elem;
	L.listsize=0;
	L.length=0;
	
}


//����
void invert(char *R,int s,int t){
	
	//���㷨������ R ���±� �� t �� s ��Ԫ������
	int k;
	char w;
	
	for(k= s; k<= (s+ t)/2.0; k++ ){
		w=R[k];
		R[k]= R[t+s-k];
		R[t+s-k]=w;	
	}  
	
} 


//��� 
void ListTraverse_Sq(SqList L){
	int i;
	for(i=0;i<L.length;i++){
		
		printf("%c    ",L.elem[i]);
	}
	printf("\n");
	
}


//����Ϊ�ձ�
void ClearList_Sq(SqList &L){

	int i;
	for(i=0; i<L.length; i++)
		L.elem[i]='\0';	
	
} 

//�ж��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList L){

	if(L.elem[0]!='\0')
			return TRUE;
	else
		return FALSE; 
} 


//��ȡ��
int ListLength_Sq(SqList L){
	
	int i=0;
	while(L.elem[i++]!='\0');
	L.length=i;
	
} 
 

//��ȡ�� i ��Ԫ��
char GetElem_Sq(SqList L,int i, char e){
	if(i<1 || i>L.length) printf("iֵ���Ϸ�"); 
	else {
		e = L.elem[i-1];
		return e;
	}
}
 
//��ȡǰ��
char PriorElem_Sq(SqList L,char cur_e,char &pre_e){
	
	int i=0;
	
	while(L.elem[i++]!=cur_e && i<=L.length);
	if(i==1 || i==L.length+1) printf("cer_eû��ǰ��");
	else {
		pre_e=L.elem[i-2];
		return pre_e;
	}
}


//��ȡ��� 
char NextElem_Sq(SqList L,char cur_e,char &next_e){
	int i=0;
	
	while(L.elem[i++]!=cur_e && i<=L.length-1);
	if(i==L.length) printf("cer_eû�к��");
	else {
		next_e=L.elem[i];
		return next_e;
	}
}






