//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int STACKINIT_SIZE=100;
const int STACKINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 


typedef int ElemType; 

//˳��ջ 
typedef struct {
	ElemType *elem;
	int top;			//ջ��ָ�� 
	int stacksize;		//��ǰ������������ 
	int incrementsize;	//Լ���������ռ��� 
}SqStack;


void InitStack_Sq(SqStack &S,int maxsize,int incresize);
         
void Push_Sq(SqStack &S,ElemType e);

bool Pop_Sq(SqStack &S,ElemType &e);
void Incrementsize_Sq(SqStack &S); 
void Stack_Traverse_Sq(SqStack S);

int main(){
	
	
	//˳��ջ�Ĳ�����֤ 
	SqStack S;
	ElemType N;
	cin>>N;
	
	
	//��ʼ�� 
	InitStack_Sq(S,100,10);
	
	//��ջ 
	while(N!=0){
		Push_Sq(S,N%8);
		N=N/8;
	}
	
	//��� 
	Stack_Traverse_Sq(S);

}

//˳��ջ��ʼ�� 
void InitStack_Sq(SqStack &S,int maxsize,int incresize){
	 
	S.elem = new ElemType[maxsize];
	
	S.top=-1;
	
	S.stacksize=maxsize;
	
	S.incrementsize=incresize;
} //InitStack_Sq



//˳��ջ�Ĳ��� 
void Push_Sq(SqStack &S,ElemType e){
	if(S.top+1==S.stacksize) Incrementsize_Sq(S);//�ռ�����
	S.elem[++S.top]=e;
}//Push_Sq

//ջ���� 
void Incrementsize_Sq(SqStack &S){
	ElemType A[S.top+S.incrementsize+1];
	ElemType *B;

	for(int i=0;i<=S.top;i++) A[i]=S.elem[i];
	
	S.stacksize=S.top+S.incrementsize+1;
	
	B=S.elem;	
	S.elem=A;	
	free(B);
}



//ɾ��ջ��Ԫ�أ����� e �н� 
bool Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==-1) return FALSE;
	e=S.elem[S.top--];
	
	return TRUE;	
}





//˳��ջ���
void Stack_Traverse_Sq(SqStack S){
	int i;
	ElemType e;
	if(S.top==-1) printf("��ջ"); 
	for(i=S.top;i>=0;i--){
		Pop_Sq(S,e);
		cout<<e<<endl;
	}
	
} 






