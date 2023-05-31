//ЁбндсН
//10200115 
#include"Stack_headerfile.h"

bool matching(char exp[]);


int main(){
	
	char w[10]={'(','(','[',']','{','}',')',')','#'};
	char x[10]={'(','(','[',')','{','}',')',')','#'};
	
	printf("%s\n",w);
	cout<<matching(w)<<endl;
	
	printf("%s\n",x);
	cout<<matching(x)<<endl;

}

bool matching(char exp[]){
	int state=1;
	ElemType e;
	SqStack S;
	char ch;
	
	InitStack_Sq(S,100,10);
	ch=*exp++;
	
	while(ch!='#' && state){
		switch(ch){
			case'(':
			case'[':
			case'{':{
				Push_Sq(S,ch);
				break;
			}
			case')':{
				GetTop_Sq(S,e);
				if(!StackEmpty_Sq(S) && e=='(')
					Pop_Sq(S,e);
				else state=0;
				break;
			}
			case']':{
				GetTop_Sq(S,e);
				if(!StackEmpty_Sq(S) && e=='[')
					Pop_Sq(S,e);
				else state=0;
				break;
			}
			case'}':{
				GetTop_Sq(S,e);
				if(!StackEmpty_Sq(S) && e=='{')
					Pop_Sq(S,e);
				else state=0;
				break;
			}
					
		}//switch
		ch=*exp++;
	}//while
	if(state && StackEmpty_Sq(S)) return TRUE;
	else return FALSE;
} //matching





