#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>

using namespace std;

typedef struct HString{
char *ch; //若是非空串，则按串长分配存储区，否则ch为空
int length; //串长度
HString()
{//默认构造函数
ch = NULL;
length = 0;
}
}HString;

void StrAssign(HString &T, char *chars){
if (T.ch) free(T.ch);//释放T原有空间
int i = 0;
char *c = NULL;
for (c = chars; *c != '\0'; ++c)//求chars的长度
{
++i;//i将记录串的长度
}
if(!i)//若用来初始化串T的chars为空
{
T.ch = NULL;
T.length = 0;
}
else
{
T.ch = (char*)malloc(i*sizeof(char));//重新分配一块能放下chars所有字符的内存空间
//if (!T.ch) return ;
for (int j = 0; j<i; ++j)
{
T.ch[j] = chars[j];//将chars中的字符放到串T中
}
T.length = i;//T的长度
}
return ;
}

void PrintHString(HString s){
cout << "字符串为:";
for (int i = 0; i<s.length; ++i)
{
cout << s.ch[i];
}
cout << endl << "长度为:" << s.length << endl << endl;
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
if (s.ch) free(s.ch);//清空串s
s.ch = (char*)malloc((s1.length + s2.length)*sizeof(char));//重新分配一块可以同时容纳s1和s2的内存空间
if (!s.ch) return ;//未分配成功，返回提示信息
for (int i = 0; i<s1.length; ++i)
{
s.ch[i] = s1.ch[i];//先将s1的内容放到串s中
}
for (int i = 0; i<s2.length; ++i)
{
s.ch[s1.length + i] = s2.ch[i];//再将s2的内容接着s1放到串s中
}
s.length = s1.length + s2.length;//串s的长度
return ;
}

void SubString(HString &Sub, HString s, int pos, int len){
if (pos<1 || pos>s.length || len<0 || len>s.length - pos + 1)
return;
if (Sub.ch)
free(Sub.ch);//释放旧的存储空间
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
HString t, s1, s2;//定义一个新串
HString Sub;

StrAssign(s1, a);//用a初始化串s1
StrAssign(s2, b);//用b初始化串s2
Concat(t, s1, s2);//连接串s1、s2，并把结果放到新串t中

PrintHString(s1);//打印串s1
PrintHString(s2);//打印串s2
PrintHString(t);//dayinchuan  t

SubString(Sub,t,3,10);//用Sub返回串t的第三个字符起长度为10的子串
PrintHString(Sub);//打印新生成的Sub串
k1=Index_BF1(s1,s2);
k2=Index_BF2(a,b);
cout<<k1<<endl;
cout<<k2<<endl;
k3=Index_KMP(s1,s2);
cout<<k3<<endl;

return 0;
}

