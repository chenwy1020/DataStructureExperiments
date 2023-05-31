//陈文宇
//10200115 
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std; 

//设计一个合理的字符串结构
//使用字符串编写字符串基本操作
//使用重载技术 对运算符重载
//编写字符串匹配算法
//BF FL KMP BM RK 
//Sunday Shift-Or Horapool Gatil-Giancarlo  Apostolico-Crochaern

//字符串本身应当是存放字符数组的地址，可以定义任意长度的要求
//字符串本身应当是动态的，可以复用已经存在的字符串，而添加新独立或非独立的字符串 
//如此字符串应当是块链结构 
typedef struct String{
	char *ch;
	int length;
	String* next; 
	String(){ //默认构造函数 
		ch=NULL;
		length=0;
		next=NULL; 
	} 

}String,*String_L;  //定义并初始化 

void StrAssign(String &T,char* S);
int StrCompare(char* T,char* S);
int StrLength(char* S);
void Concat(String &T, char *S1, char *S2);
void SubString(char *Sub,char* S,int pos, int len);
void GetNext(char* S,int* next,int lenS);
//字符串匹配算法 
int Index_BF(char* S, char* T, int pos);
int Index_FL(char* T, char* S, int pos); 
int Index_KMP(char* T, char *S, int pos);

int  main(){
	String T;
	 
	
	char a[50]="hello world! ";
	char c[50]="ChenWenyu! abcdefg";
	char b[1000];
	char d[50];

	StrAssign(T,a); 
	
	cout<<"a="<<a<<endl;
	cout<<"a_length="<<StrLength(a)<<endl;
	
	cout<<"b="<<T.ch<<endl;
	cout<<"b_length="<<StrLength(T.ch)<<endl;
	
	cout<<"a compare b ="<<StrCompare(T.ch,a)<<endl;
	
	Concat(T,a,c);
	
	
	cout<<"b="<<T.ch<<endl;
	cout<<"b_length="<<StrLength(T.ch)<<endl;
	
	
	SubString(d,T.ch,6,5);
	printf("d = %s\n",d);
	cout<<"d_length = "<<StrLength(d)<<endl;
	
	cout<<"暴力匹配算法：";
	cout<< Index_BF(T.ch ,d,0)<<endl;
	cout<<"首尾匹配算法：";
	cout<< Index_FL(T.ch ,d,0)<<endl;	
	cout<<"KMP匹配算法：";
	cout<< Index_KMP(T.ch ,d,0)<<endl;
}

//字符串基本操作 
void StrAssign(String &T,char* S){
	if(T.ch) free(T.ch);
	int k=0;
	while(S[k++]!='\0');
	T.ch=(char*)malloc(sizeof(char)*k);
	for(int i=0; i<k; i++)  T.ch[i]=S[i];
	T.length=k;
}

int StrCompare(char* T,char* S){
	int i;
	for(i=0; S[i]==T[i] && S[i] !='\0' && T[i] != '\0'; i++ );
	if(S[i] = T[i]) return 0;
	if(S[i] < T[i]) return -1;
	if(S[i] > T[i]) return 1;
}
//不包括'\0' 的元素的个数 
int StrLength(char* S){
	int k=0;
	while(S[k++] != '\0');
	return k-1;
}

void Concat(String &T, char *S1, char *S2){
	
	int i=0,k=0;
	k=StrLength(S1)+StrLength(S2)+1;
	T.ch=(char*)malloc( sizeof(char)*k);
	k=0;
	while(S1[i]!= '\0') T.ch[k++]=S1[i++];
	i=0;
	while(S2[i]!= '\0') T.ch[k++]=S2[i++];
	T.ch[k]='\0';
	
}

void SubString(char *Sub,char* S,int pos, int len){
	int i; 
	for(i=0; i<len ;i++){
		Sub[i]=S[i+pos];
	}
	Sub[i]='\0';
}

//暴力匹配算法 
int Index_BF(char* S, char* T, int pos){
	int i=pos,j=0;
	while(S[i+j] != '\0' && T[j] != '\0'){
		if( S[i+j] == T[j]) j++;
		else{i++; j=0;}
	} 
	if(T[j]=='\0') return i;
	else return -1;

}

//首尾匹配算法 
int Index_FL(char* T, char* S, int pos){
	int lenS=StrLength(S);
	int lenT=StrLength(T);
	int i=pos,k=0,j=0; 
	if(lenT-pos<lenS) return -1;
	else{
		for(; i<=lenT-lenS; i++){
			for(; k<=lenS/2;k++){
				if(T[i+k] != S[k] ) break;
				if(T[i+lenS-1-k]!=S[lenS-1-k]) break;
				if(k==lenS/2) j=1;
			}
			if(j) return i;
			else k=0;					
		}
	}
	return -1;
		
}

int Index_BM(char* T, char *S, int pos){
	int lenS=StrLength(S);
	int lenT=StrLength(T);
	int* next[lenS-1];
	int i=pos,j=0; 
	if(lenT-pos<lenS) return -1;
	else{
		for(; i<=lenT-lenS; ){
			
				;
			
		}
		
	}
	
	
}

//匹配失败后。子串 移至 失配位前的最长公共后缀上，即可 next组便是获取移动位序的数组 
int Index_KMP(char* T, char *S, int pos){
	int lenS=StrLength(S);
	int lenT=StrLength(T);
	int next[lenS];
	GetNext(S,next,lenS);
	int i=pos,j=0,k; 
	if(lenT-pos<lenS) return -1;
	else{
		while(i<=lenT-lenS){
			while(j<lenS && T[i+j]==S[j]) j++;
			if(j==lenS) return i;
			else {
				i=i+lenS-next[j];
				j=next[j]+1;
			}
		}
	}
	return -1;
}

void GetNext(char* S,int* next,int lenS){

	int i=0,j=-1; // 以S[i]结尾失配 的 前 i 个元素的最长公共后缀的首位索引 为 next[i] 
	next[0]=-1;  //默认 S[0] 结尾为失配 默认其索引为 -1 
   
    while (i < lenS){
        if (j == -1 || S[i] == S[j]){
        	++i;++j;
            next[i] = j;
        }   
		else j = next[j];
	}
}







