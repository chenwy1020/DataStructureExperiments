//������
//10200115 
#include"Stack_headerfile.h"

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








