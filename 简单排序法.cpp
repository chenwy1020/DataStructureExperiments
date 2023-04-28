//������
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 


const int MAXSIZE=20;
const bool TRUE=1;
const bool FALSE=0; 

//����������� 
typedef int KeyType;
typedef char InfoType; 

typedef struct{
	KeyType key;
	InfoType val;
}RcdType;

typedef struct {
	RcdType r[MAXSIZE+1]; //R[0]���û���Ϊ�б��־�ġ��ڱ���Ԫ��
	int length; 
}SqList;


//�������� 
void SelectPass(SqList &L,int i); 
void SelectSort(SqList &L);

void InsertPass(SqList &L,int i);
void InsertSort(SqList &L);

void BubbleSort(SqList &L);

int Partition(RcdType R[], int low, int high);
void Qsort(RcdType R[], int s,int t);
void QuickSort(SqList &L);

void Merge(RcdType SR[], RcdType TR[], int i, int m, int n);
void Msort(RcdType SR[], RcdType TR1[], int s,int t);
void MergeSort(SqList &L);


int main(){
	SqList L,M,N,O,P;

	//L.r=new RcdType[MAXSIZE+1];
	L.length=8; M.length=8; N.length=8; O.length=8; P.length=8; 
	
	L.r[1].key=49;	
	L.r[2].key=38;	
	L.r[3].key=65;	
	L.r[4].key=49;	
	L.r[5].key=76;	
	L.r[6].key=13;	
	L.r[7].key=27;	
	L.r[8].key=52;
	
    for(int i=1; i<=8; i++){
    	M.r[i].key=L.r[i].key;
    	N.r[i].key=L.r[i].key;
    	O.r[i].key=L.r[i].key;
    	P.r[i].key=L.r[i].key;
	}
	
	
	//------------------------------------------------------- 
	printf("ѡ������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=L.length; i++){
		cout<<L.r[i].key<<"  "<<endl;
	}
	SelectSort(L);
	cout<<"�����"<<endl;
	for(int i=1;i<=L.length; i++){
		cout<<L.r[i].key<<"  "<<endl;
	}
	
	
	//-------------------------------------------------------- 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=M.length; i++){
		cout<<M.r[i].key<<"  "<<endl;
	}
	InsertSort(M);
		cout<<"�����"<<endl;
	for(int i=1;i<=M.length; i++){
		cout<<M.r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------------------- 
	printf("\n\n\nð������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=N.length; i++){
		cout<<N.r[i].key<<"  "<<endl;
	}
	BubbleSort(N);
		cout<<"�����"<<endl;
	for(int i=1;i<=N.length; i++){
		cout<<N.r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------------------- 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=O.length; i++){
		cout<<O.r[i].key<<"  "<<endl;
	}
	QuickSort(O);
		cout<<"�����"<<endl;
	for(int i=1;i<=O.length; i++){
		cout<<O.r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------ 
	printf("\n\n\n�鲢����\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=P.length; i++){
		cout<<P.r[i].key<<"  "<<endl;
	}
	MergeSort(P);
		cout<<"�����"<<endl;
	for(int i=1;i<=P.length; i++){
		cout<<P.r[i].key<<"  "<<endl;
	}
	

}


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

//˳����ѡ������ 
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

 
//�鲢����
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n){
	int j=m+1;
	int k;
	for(j=m+1,k=i; i<=m && j<=n; k++){
		if(SR[i].key<=SR[j].key) TR[k]=SR[i++];
		else TR[k]=SR[j++];
	}//for
	while(i<=m) TR[k++]=SR[i++];
	while(j<=n) TR[k++]=SR[j++];
	
} //Merge

void Msort(RcdType SR[], RcdType TR1[], int s,int t){
	RcdType TR2[t-s+1];
	int m;
	if(s==t) TR1[s]=SR[s];
	else{
		m=(s+t)/2;
		Msort(SR,TR2,s,m);
		Msort(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
	}//else
	
}//Msort

void MergeSort(SqList &L){
	Msort(L.r, L.r, 1, L.length);
}//MergeSort




