//������
//10200115 
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std; 

//���һ��������ַ����ṹ
//ʹ���ַ�����д�ַ�����������
//ʹ�����ؼ��� �����������
//��д�ַ���ƥ���㷨
//BF FL KMP BM RK 
//Sunday Shift-Or Horapool Gatil-Giancarlo  Apostolico-Crochaern

//�ַ�������Ӧ���Ǵ���ַ�����ĵ�ַ�����Զ������ⳤ�ȵ�Ҫ��
//�ַ�������Ӧ���Ƕ�̬�ģ����Ը����Ѿ����ڵ��ַ�����������¶�����Ƕ������ַ��� 
//����ַ���Ӧ���ǿ����ṹ 
typedef struct String{
	char *ch;
	int length;
	String* next; 
	String(){ //Ĭ�Ϲ��캯�� 
		ch=NULL;
		length=0;
		next=NULL; 
	} 

}String,*String_L;  //���岢��ʼ�� 

void StrAssign(String &T,char* S);
int StrCompare(char* T,char* S);
int StrLength(char* S);
void Concat(String &T, char *S1, char *S2);
void SubString(char *Sub,char* S,int pos, int len);
void GetNext(char* S,int* next,int lenS);
//�ַ���ƥ���㷨 
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
	
	cout<<"����ƥ���㷨��";
	cout<< Index_BF(T.ch ,d,0)<<endl;
	cout<<"��βƥ���㷨��";
	cout<< Index_FL(T.ch ,d,0)<<endl;	
	cout<<"KMPƥ���㷨��";
	cout<< Index_KMP(T.ch ,d,0)<<endl;
}

//�ַ����������� 
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
//������'\0' ��Ԫ�صĸ��� 
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

//����ƥ���㷨 
int Index_BF(char* S, char* T, int pos){
	int i=pos,j=0;
	while(S[i+j] != '\0' && T[j] != '\0'){
		if( S[i+j] == T[j]) j++;
		else{i++; j=0;}
	} 
	if(T[j]=='\0') return i;
	else return -1;

}

//��βƥ���㷨 
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

//ƥ��ʧ�ܺ��Ӵ� ���� ʧ��λǰ���������׺�ϣ����� next����ǻ�ȡ�ƶ�λ������� 
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

	int i=0,j=-1; // ��S[i]��βʧ�� �� ǰ i ��Ԫ�ص��������׺����λ���� Ϊ next[i] 
	next[0]=-1;  //Ĭ�� S[0] ��βΪʧ�� Ĭ��������Ϊ -1 
   
    while (i < lenS){
        if (j == -1 || S[i] == S[j]){
        	++i;++j;
            next[i] = j;
        }   
		else j = next[j];
	}
}







