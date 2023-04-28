//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int STACKINIT_SIZE=100;
const int STACKINCREMENT=10;
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
typedef struct LNode{    //typedef���������ýṹ�������ʹ�ù��� ����ṹ����� LNode p ;LNode *p;�м򻯵�Ч�� 
	ElemType date;
	struct LNode *next; //�ṹ��������-next��Ϊָ�� ָ�� �ṹ��; 
}LNode,*LinkList;    // LinkList ��ͨ���ṹ��������ָ��������ṹ��ָ�룩���൱��LNode *LinkList;  LinkList��ָ����ֽṹ���ָ�� 
//LNode�������һ���ṹ�壬��������������һ��ָ�����͡� 

typedef LinkList LinkStack;

//��������
//�˴� & �������������൱��Ŀ��������������ƣ�����Ŀ��ԭ���ƺ����������Ҳ����ٰѸ���������Ϊ�����������ı���
//���� λ�������ָ������� û�й�ϵ 
//һ��������ͨ������ͨ��ͬ���͵ı��� ��ֵ���������������ͷ��ڴ棬����ָ������ֱ�ӶԵ�ַ��ŵ�ֵ���㣬���Ա�֤�����ͷ� 
void InitStack_Sq(SqStack &S,int maxsize,int incresize);
void DestroyStack_Sq(SqStack &S);
void ClearStack_Sq(SqStack &S);
bool StackEmpty_Sq(SqStack S);           
void Push_Sq(SqStack &S,ElemType e);
void GetTop_Sq(SqStack S,ElemType &e);
bool Pop_Sq(SqStack &S,ElemType &e);
void Incrementsize_Sq(SqStack &S);
void Stack_Traverse_Sq(SqStack S);

int main(){
	
	
	//˳��ջ�Ĳ�����֤ 
	SqStack S;
	ElemType e;
	
	//��ʼ�� 
	InitStack_Sq(S,100,10);
	
	//��ջ 
	Push_Sq(S,'a');
	Push_Sq(S,'b');
	Push_Sq(S,'c');
	Push_Sq(S,'d');
	
	Stack_Traverse_Sq(S);

	//��ջ
	Pop_Sq(S,e); 
	Stack_Traverse_Sq(S);
	
	//��ջ����֤ 
}

//˳��ջ��ʼ�� 
void InitStack_Sq(SqStack &S,int maxsize,int incresize){
	 
	S.elem = new ElemType[maxsize];
	
	S.top=-1;
	
	S.stacksize=maxsize;
	
	S.incrementsize=incresize;
} //InitStack_Sq


//˳��ջ������
void DestroyStack_Sq(SqStack &S){
	
	delete[] S.elem;
	S.stacksize=0;
	S.top=-1;
} 


//˳��ջ�����
void ClearStack_Sq(SqStack &S){
	int i;
	ElemType e;
	for(i=S.top;i>=0;i--) Pop_Sq(S,e);
} 


//�ж�˳��ջ�Ƿ�Ϊ��ջ 
bool StackEmpty_Sq(SqStack S){
	if(S.top==-1) return TRUE;
	else return FALSE;
}


//˳��ջ�Ĳ��� 
void Push_Sq(SqStack &S,ElemType e){
	if(S.top+1==S.stacksize) Incrementsize_Sq(S);//�ռ�����
	S.elem[++S.top]=e;
}//Push_Sq


//��ȡջ��Ԫ�أ����� e �н� 
void GetTop_Sq(SqStack S,ElemType &e){
	e=S.elem[S.top];	
}


//ɾ��ջ��Ԫ�أ����� e �н� 
bool Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==-1) return FALSE;
	e=S.elem[S.top--];
	
	return TRUE;	
}


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



//��ջ�Ļ�������
//��ʼ�� 
void InitStack_L(LinkStack &S){
	S=NULL;
}//InitStack_L

//Ԫ����ջ 
void Push_L(LinkStack &S,ElemType e){
	LNode *p;
	p=new LNode;
	p->date=e;
	p->next=S;
	S=p;
	
}//Push_L

//ջ��Ԫ�س�ջ 
bool Pop_L(LinkStack &S,ElemType &e){
	if(S==NULL) return FALSE;
	else{
		LNode *p;
		p=S;
		e=p->date;
		S=p->next;
		delete p;	
	}
	
}


