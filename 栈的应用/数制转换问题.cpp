//陈文宇
//10200115 
#include"Stack_headerfile.h"

int main(){
	
	//顺序栈的操作验证 
	SqStack S;
	ElemType N;
	cin>>N;
	
	//初始化 
	InitStack_Sq(S,100,10);
	
	//入栈 
	while(N!=0){
		Push_Sq(S,N%8);
		N=N/8;
	}

	//输出 
	Stack_Traverse_Sq(S);

}








