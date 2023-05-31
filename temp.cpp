#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>

using namespace std; 
//���һ��������ַ����ṹ
//ʹ���ַ�����д�ַ�����������
//ʹ�����ؼ��� �����������
//��д�ַ���ƥ���㷨
//BF KMP RK 
typedef struct HString
{
	char *ch; //���Ƿǿմ����򰴴�������洢��������chΪ��
	int length; //������
	
	HString()
	{//Ĭ�Ϲ��캯��
		ch = NULL;
		length = 0;
	}
	
}HString;

void StrAssign(HString &T, char *chars)//����һ����ֵ���ڴ�����chars�Ĵ�T
{
	if (T.ch) free(T.ch);//�ͷ�Tԭ�пռ�
	int i = 0;
	char *c = NULL;
	for (c = chars; *c != '\0'; ++c)//��chars�ĳ���
	{
		++i;//i����¼���ĳ���
	}
	if (!i)//��������ʼ����T��charsΪ��
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

void PrintHString(HString s)//��ӡ��s�ĺ���
{
	cout << "The string is :";
	for (int i = 0; i<s.length; ++i)
	{
		cout << s.ch[i];
	}
	cout << endl << "Length is :" << s.length << endl << endl;
}

int StrCompare(HString s, HString t)//��s>t����ֵ>0;s=t����ֵ=0��s<t����ֵ<0
{
	int i;
	for (i = 0; i<s.length&&i<t.length; ++i)
	{
		if (s.ch[i] != t.ch[i]) return s.ch[i] - t.ch[i];
	}
	return s.length - t.length;
}

void ClearString(HString &s)//�����s
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
	}
	s.length = 0;
	return ;
}

void Concat(HString &s, HString s1, HString s2)//��t������s1��s2������ɵ��´�
{
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

void SubString(HString &Sub, HString s, int pos, int len)//��Sub���ش�s�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
{
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

int main()
{
	char a[8] = "abcdefg";
	char b[8] = "hijklmn";
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
	return 0;
}

