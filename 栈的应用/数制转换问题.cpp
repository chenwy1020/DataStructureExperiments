//陈文宇
//10200115 
#include"Stack_headerfile.h"

int main(){
	
	//顺序栈的操作验证 
	SqStack S;
	ElemType N;
	cout<<"十进制为:";
	cin>>N;
	
	//初始化 
	InitStack_Sq(S,100,10);
	
	//入栈 
	//将整数取余，余数入栈
	while(N!=0){
		Push_Sq(S,N%8);
		N=N/8;
	}

	//输出 
	
	cout<<"八进制为:"; 
	Stack_Traverse_Sq(S);

}








