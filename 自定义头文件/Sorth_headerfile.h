//������
//10200115 

//#include "stdafx.h" //�Լ�д��ͷ�ļ�һ����˫���ţ����Բ��Ǽ�����
//#inndef STDAFX_H //�Ȼ�����Ҫע��ĵ㣬�������
//#define STDAFX_H
//#include <iostream> //��Ͳ���˵�˰ɣ��������ˣ����е�5�е�Ҳ��
//using namespace std;

const int MAXSIZE=20;

//����������� 
typedef int KeyType;
typedef char InfoType; 
//Ϊ��ʹ�õĸ��ӹ㷺�����Ǽ��ٶ������͵�Լ�������Ҷ��ڶ������ݽṹ��ͳһ���Ĵ��� 

typedef struct{
	KeyType key;
	InfoType val;
}RcdType;

typedef struct {
	RcdType r[MAXSIZE+1]; //R[0]���û���Ϊ�б��־�ġ��ڱ���Ԫ ��
	int length; 
}SqList;



//ѡ������
void SelectPass(SqList &L,int i){  
	//��֪L.r[1:1:i-1]�йؼ��ַǵݼ����򣬱��㷨ʵ�ֵ�i��ѡ������
	//����L.r[i:1:n]�ļ�¼��ѡ���ؼ��� ��С�ļ�¼L.r[j]��r[i]���н���
	int j=i;
	RcdType W;
	
	for(int k=i+1; k<=L.length; k++)
		if(L.r[k].key<L.r[j].key) j=k;
	if(i!=j){
		W=L.r[j];
		L.r[j]=L.r[i];
		L.r[i]=W;
	}
	
}// SelectPass

void SelectSort(SqList &L){
	RcdType W;
	int j;
	int k;
	for(int i=1; i<L.length; i++){
		j=i;
		for(k=i+1; k<=L.length; k++){
			if(L.r[k].key<L.r[j].key) j=k;
		}
		if(i!=j){
			W=L.r[j]; L.r[j]=L.r[i]; L.r[i]=W;			
		}
	}
}//SelectSort


//�������� 
void InsertPass(SqList &L,int i){
	int j=i-1;
	L.r[0]=L.r[i];
	
	for(; L.r[0].key < L.r[j].key; j--)
		L.r[j+1]=L.r[j];

	L.r[j+1]=L.r[j];
}//InsertPass

//˳���Ĳ������� 
void InsertSort(SqList &L){
	int j;
	for(int i=2; i<=L.length; i++){
		if(L.r[i].key < L.r[i-1].key){
			L.r[0]=L.r[i];
			for(j=i-1; L.r[0].key<L.r[j].key; j--)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}//if
	}//for
}//InsertSort


// ˳������������ 
void BubbleSort(SqList &L){
	int i=L.length,LastExchangeIndex;
	RcdType W;
	int j;
	while(i>1){
		LastExchangeIndex=1;
		for(j=1; j<i; j++){
			if(L.r[j+1].key<L.r[j].key){
				W=L.r[j]; L.r[j]=L.r[j+1]; L.r[j+1]=W;
				LastExchangeIndex=j;
			}//if
		}//for
		i=LastExchangeIndex;
	}//while 
} //BubbleSort

//���������㷨
int Partition(RcdType R[], int low, int high){
	R[0]=R[low];
	KeyType pivotkey=R[low].key;
	while(low<high){
		while(low<high && R[high].key>=pivotkey) --high;
		if(low<high) R[low++]=R[high];
		while(low<high && R[low].key<=pivotkey) ++low;
		if(low<high) R[high--]=R[low];
	}//while
	R[low]=R[0];
	//printf("������");
	return low;
	
} //Partition

void Qsort(RcdType R[], int s,int t){
	int pivotloc;
	if(s<t){
		pivotloc=Partition(R,s,t);
		Qsort(R,s,pivotloc-1);
		Qsort(R,pivotloc+1,t); 
	}//if
	
}//Qsort

void QuickSort(SqList &L){
	Qsort(L.r,1,L.length);
}//QuickSort


//#endif
