//陈文宇
//10200115 

//#include "stdafx.h" //自己写的头文件一定是双引号，绝对不是尖括号
//#inndef STDAFX_H //等会有需要注意的点，埋个伏笔
//#define STDAFX_H
//#include <iostream> //这就不用说了吧，老朋友了，还有第5行的也是
//using namespace std;

const int MAXSIZE=20;

//定义变量类型 
typedef int KeyType;
typedef char InfoType; 
//为了使用的更加广泛，我们减少对于类型的约束，并且对于多种数据结构做统一化的处理 

typedef struct{
	KeyType key;
	InfoType val;
}RcdType;

typedef struct {
	RcdType r[MAXSIZE+1]; //R[0]闲置或作为判别标志的“哨兵单元 ”
	int length; 
}SqList;



//选择排序
void SelectPass(SqList &L,int i){  
	//已知L.r[1:1:i-1]中关键字非递减排序，本算法实现第i躺选择排序
	//即在L.r[i:1:n]的记录中选出关键字 最小的记录L.r[j]和r[i]进行交换
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


//插入排序 
void InsertPass(SqList &L,int i){
	int j=i-1;
	L.r[0]=L.r[i];
	
	for(; L.r[0].key < L.r[j].key; j--)
		L.r[j+1]=L.r[j];

	L.r[j+1]=L.r[j];
}//InsertPass

//顺序表的插入排序 
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


// 顺序表的起泡排序 
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

//快速排序算法
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
	//printf("陈文宇");
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
