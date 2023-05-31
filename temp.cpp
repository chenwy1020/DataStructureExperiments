#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>

using namespace std; 
//设计一个合理的字符串结构
//使用字符串编写字符串基本操作
//使用重载技术 对运算符重载
//编写字符串匹配算法
//BF KMP RK 
typedef struct HString
{
	char *ch; //若是非空串，则按串长分配存储区，否则ch为空
	int length; //串长度
	
	HString()
	{//默认构造函数
		ch = NULL;
		length = 0;
	}
	
}HString;

void StrAssign(HString &T, char *chars)//生成一个其值等于串常量chars的串T
{
	if (T.ch) free(T.ch);//释放T原有空间
	int i = 0;
	char *c = NULL;
	for (c = chars; *c != '\0'; ++c)//求chars的长度
	{
		++i;//i将记录串的长度
	}
	if (!i)//若用来初始化串T的chars为空
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

void PrintHString(HString s)//打印串s的函数
{
	cout << "The string is :";
	for (int i = 0; i<s.length; ++i)
	{
		cout << s.ch[i];
	}
	cout << endl << "Length is :" << s.length << endl << endl;
}

int StrCompare(HString s, HString t)//若s>t返回值>0;s=t返回值=0；s<t返回值<0
{
	int i;
	for (i = 0; i<s.length&&i<t.length; ++i)
	{
		if (s.ch[i] != t.ch[i]) return s.ch[i] - t.ch[i];
	}
	return s.length - t.length;
}

void ClearString(HString &s)//清除串s
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
	}
	s.length = 0;
	return ;
}

void Concat(HString &s, HString s1, HString s2)//用t返回由s1和s2连接组成的新串
{
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

void SubString(HString &Sub, HString s, int pos, int len)//用Sub返回串s的第pos个字符起长度为len的子串
{
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

int main()
{
	char a[8] = "abcdefg";
	char b[8] = "hijklmn";
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
	return 0;
}

