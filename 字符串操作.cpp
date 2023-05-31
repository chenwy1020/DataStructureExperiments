#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>

using namespace std;

typedef struct HString{
char *ch; //���Ƿǿմ����򰴴�������洢��������chΪ��
int length; //������
HString()
{//Ĭ�Ϲ��캯��
ch = NULL;
length = 0;
}
}HString;

void StrAssign(HString &T, char *chars){
if (T.ch) free(T.ch);//�ͷ�Tԭ�пռ�
int i = 0;
char *c = NULL;
for (c = chars; *c != '\0'; ++c)//��chars�ĳ���
{
++i;//i����¼���ĳ���
}
if(!i)//��������ʼ����T��charsΪ��
{
T.ch = NULL;
T.length = 0;
}
else
{
T.ch = (char*)malloc(i*sizeof(char));//���·���һ���ܷ���chars�����ַ����ڴ�ռ�
//if (!T.ch) return ;
for (int j = 0; j<i; ++j)
{
T.ch[j] = chars[j];//��chars�е��ַ��ŵ���T��
}
T.length = i;//T�ĳ���
}
return ;
}

void PrintHString(HString s){
cout << "�ַ���Ϊ:";
for (int i = 0; i<s.length; ++i)
{
cout << s.ch[i];
}
cout << endl << "����Ϊ:" << s.length << endl << endl;
}

int StrCompare(HString s, HString t){
int i;
for (i = 0; i<s.length&&i<t.length; ++i)
{
if (s.ch[i] != t.ch[i]) return s.ch[i] - t.ch[i];
}
return s.length - t.length;
}

void ClearString(HString &s){
if (s.ch)
{
free(s.ch);
s.ch = NULL;
}
s.length = 0;
return ;
}

void Concat(HString &s, HString s1, HString s2){
if (s.ch) free(s.ch);//��մ�s
s.ch = (char*)malloc((s1.length + s2.length)*sizeof(char));//���·���һ�����ͬʱ����s1��s2���ڴ�ռ�
if (!s.ch) return ;//δ����ɹ���������ʾ��Ϣ
for (int i = 0; i<s1.length; ++i)
{
s.ch[i] = s1.ch[i];//�Ƚ�s1�����ݷŵ���s��
}
for (int i = 0; i<s2.length; ++i)
{
s.ch[s1.length + i] = s2.ch[i];//�ٽ�s2�����ݽ���s1�ŵ���s��
}
s.length = s1.length + s2.length;//��s�ĳ���
return ;
}

void SubString(HString &Sub, HString s, int pos, int len){
if (pos<1 || pos>s.length || len<0 || len>s.length - pos + 1)
return;
if (Sub.ch)
free(Sub.ch);//�ͷžɵĴ洢�ռ�
if (!len)
{
Sub.ch = NULL;
Sub.length = 0;
}
else
{
Sub.ch = (char*)malloc(len*sizeof(char));
for (int i = 0; i < len; i++)
{
Sub.ch[i] = s.ch[pos++];
}
Sub.length = len;
}
}

int Index_BF1(HString s,HString t){
	int i=0,j=0;
	while (i<s.length && j<t.length){
		if(s.ch[i] == t.ch[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=t.length)  return i-t.length+1;
	else  return 0;
} 

int Index_BF2(char s[],char t[]){
	int i=0,j=0;
	while(s[i+j]!='\0' && t[j]!='\0')
	    if (s[i+j] == t[j]) j++;
	    else {i++;j=0;}
	if (t[j] == '\0') return i+1;
	else return -1;
}

void getnext(HString t,int next[]){
	int j = 0,k = -1;
	next[0]=-1;
	while(j<t.length-1){
		if (k == -1||t.ch[j] == t.ch[k] ){
			j++;k++;
			next[j]=k;
		}
		else k=next[k];
	}
}

int Index_KMP(HString s,HString t){
	int i=0,j=0;int next[20];
	getnext(t,next);
	while (i<s.length && j<t.length){
		if (j == -1 || s.ch[i] == t.ch[j]){
			i++;j++;
		}
		else j=next[j];
	}
	if(j>=t.length) return i-t.length+1;
	else return -1;
}


 
int main(){
	int k1,k2,k3;
char a[8] = "abcdefg";
char b[8] = "def";
HString t, s1, s2;//����һ���´�
HString Sub;

StrAssign(s1, a);//��a��ʼ����s1
StrAssign(s2, b);//��b��ʼ����s2
Concat(t, s1, s2);//���Ӵ�s1��s2�����ѽ���ŵ��´�t��

PrintHString(s1);//��ӡ��s1
PrintHString(s2);//��ӡ��s2
PrintHString(t);//dayinchuan  t

SubString(Sub,t,3,10);//��Sub���ش�t�ĵ������ַ��𳤶�Ϊ10���Ӵ�
PrintHString(Sub);//��ӡ�����ɵ�Sub��
k1=Index_BF1(s1,s2);
k2=Index_BF2(a,b);
cout<<k1<<endl;
cout<<k2<<endl;
k3=Index_KMP(s1,s2);
cout<<k3<<endl;

return 0;
}

