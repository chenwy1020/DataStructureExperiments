//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 


typedef char ElemType; 

//˳��ջ 
typedef struct {
	ElemType *elem;
	int top;			//ջ��ָ�� 
	int stacksize;		//��ǰ������������ 
	int incrementsize;	//Լ���������ռ��� 
}SqStack;

//��ʽջ
typedef struct LNode{    
	ElemType date;
	struct LNode *next; 
}LNode,*LinkStack;

int main(){
	
}
