 //10200115 
//陈文宇 
#include"Stack_headerfile.h"
#include<cmath>
#include<cstdlib>

int Operate(ElemType a,ElemType ch,ElemType b);
bool OpMember1(ElemType ch);//判断是否为操作符 
bool OpMember2(ElemType ch);//判断是否为运算符 
bool precede(ElemType c,ElemType ch);//优先级判定 
void transform(ElemType Suffix[],ElemType exp[]);//表达式转换为后缀式 
int evaluation(ElemType Suffix[]);//后缀式求值 

int main(){
	int a=2,b=3,c=3,d=4,e=2,f=5;
	int exp[14]={a,'*',b,'+','(',c,'-',d,'/',e,')','*',f,'#'};
	int Suffix[14];
	
	transform(Suffix,exp);
	/*
	for(int i=0;i<14;i++){
		cout<<exp[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<14;i++){
		cout<<Suffix[i]<<"  ";
	}
	cout<<endl;
	*/
	cout<<evaluation(Suffix)<<endl;
	
	
}

int Operate(ElemType a,ElemType ch,ElemType b){
	
	switch(ch){
		case'+':{
			return a+b;
			break;
		}
		case'-':{
			return a-b;
			break;
		}
		case'*':{
			return a*b;
			break;
		}
		case'/':{
			return a/b;
			break;
		}
		case'^':{
			return powl(a,b);
			break;
		}
		default:{
			break;
		}
	}
}

bool OpMember1(ElemType ch){
	switch(ch){
		case'#':
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'^':{
			return TRUE;
			break;
		}
		default:{
			return FALSE;
			break;
		}
	}
}

bool OpMember2(ElemType ch){
	switch(ch){
		case'+':
		case'-':
		case'*':
		case'/':
		case'^':{
			return TRUE;
			break;
		}
		default:{
			return FALSE;
			break;
		}
	}
}

bool precede(ElemType c,ElemType ch){
	int a=0;
	int b=0;
	switch(c){
		case'#':{a=-1;break;}
		case'(':{a=0; break;}
		case'+':
		case'-':{a=1; break;}	
		case'*':
		case'/':
		case')':{a=2; break;}
		case'^':{a=3; break;}

	}
	switch(ch){
		case'#':{b=-1;break;}
		case'(':{b=0; break;}
		case'+':
		case'-':{b=1; break;}	
		case'*':
		case'/':
		case')':{b=2; break;}
		case'^':{b=3; break;}

	}

	return (a>=b ? TRUE:FALSE);
}

void transform(ElemType Suffix[],ElemType exp[]){
	SqStack S;
	ElemType ch,c;
	int k=0;

	ch=*exp++;
	InitStack_Sq(S,100,10);
	Push_Sq(S,'#');

	
	while(!StackEmpty_Sq(S)){
		
		if( !OpMember1(ch) ) Suffix[k++]=ch;//操作数直接入后缀式栈 
		else{
			switch(ch){
				case'(': {Push_Sq(S,ch); break; }
				case')':{
					Pop_Sq(S,c);
					while(c!='('){
						Suffix[k++]=c;
						Pop_Sq(S,c);
					}//while
					break;
				}
				default:{
					while(GetTop_Sq(S,c) && precede(c,ch)){//precede是判断运算符的优先级的 
						Suffix[k++]=c;
						Pop_Sq(S,c);
					}//while 将栈中连续地向前 将优先级不小于当前运算符优先级的运算符发送给后缀式
					if(ch != '#') Push_Sq(S,ch);
					break;
				}//default
			}//switch

		}//else
		
		if(ch != '#') ch=*exp++;
		
	}//while

	
}//transform

//根据后缀式求解结果 
int evaluation(ElemType Suffix[]){
	SqStack S;
	ElemType ch,a,b,result;

	ch=*Suffix++;
	InitStack_Sq(S,100,10);
	
	while(ch != '#'){
		if( !OpMember2(ch) ) Push_Sq(S,ch);//OpMember2(ch)判定其是否为运算符 
		else {
			Pop_Sq(S,b); Pop_Sq(S,a);
			Push_Sq(S,Operate(a,ch,b));//Operate(a,ch,b)操作数 运算符 操作数 (计算) 
		}//else
		
		ch=*Suffix++;
	}//while
	
	Pop_Sq(S,result);
	return result;
}



