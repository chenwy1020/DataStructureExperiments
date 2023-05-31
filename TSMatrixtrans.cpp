//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std; 
const int MAXSIZE=100;

typedef int ElemType;
 
typedef struct{
	int i,j;				//非零元的行下标和列下标 
	ElemType e;				//该非零元的元素值 
}Triple;
typedef struct{
	Triple data[MAXSIZE];	//非零元三元组表，data[0]未用
	int mu,nu,tu;			//稀疏矩阵的行数，列数和非零元个数
}TSMatrix;		
		 
void TSMattrans(int** M,TSMatrix &MS,int m,int n);
void transpose(int** M, int** T,int m,int n);
void coutMat(int** M,int m, int n);
void coutTSMat(TSMatrix MS);
void createRpos(TSMatrix MS,int* rpos);
void FastTransposeTSMatrix(TSMatrix MS,TSMatrix &TS);

 
int main(){
	
	int m=3,n=3;
	int** M=new int*[m];
	int** T=new int*[m];
	TSMatrix MS,TS;
	
	//初始化 
	for(int i=0;i<m;i++){
		M[i]=new int[n];
		T[i]=new int[n];
	}
	MS.mu=m;	MS.nu=n;
	TS.mu=n;	TS.nu=m;
	for(int p=0;p<m;p++){
		for(int q=0;q<n;q++){
			M[p][q]=0;
		}
		M[p][p]=p+1;
	}
	M[0][n-1]=1;
	
	//以三元组 形式存储
	TSMattrans(M,MS,m,n);
	coutMat(M,m,n);
	cout<<"MSMatrix = "<<endl;
	coutTSMat(MS);
	
	//一般矩阵转置
	transpose(M,T,m,n);
	TSMattrans(T,TS,m,n);
	coutMat(T,m,n);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	
	//稀疏矩阵装置 
	FastTransposeTSMatrix(MS,TS);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	
	
	
	//销毁矩阵 
	for(int p=0;p<m;p++){
		delete[] M[p];
		delete[] T[p];
	}
	delete[] M;
	delete[] T;
	
	
}
//用于录入稀疏矩阵 并以三元组 形式存储 
void TSMattrans(int** M,TSMatrix &MS,int m,int n){
	int k=1;
	for(int p=0; p<m; p++){
		for(int q=0; q<n; q++){
			if(M[p][q] != 0 ){
				MS.data[k].i=p+1;
				MS.data[k].j=q+1;
				MS.data[k].e=M[p][q];
				k++;
			}
		}
	}
	MS.tu=k-1;
}

//num[] 计数器  rops[] 计序器 
void createRpos(TSMatrix MS,int* rpos){
	int nums[MS.nu+1];
	int p;
	//rops 求 M 中每一列的第一个非零元 在T.data 中的序号   称为位序器
	//nums 求 M 中每一列的非零元的个数 
	for(p=1;p<=MS.nu;p++) nums[p]=0;
	for(p=1;p<=MS.tu;p++) nums[MS.data[p].j]++;
	rpos[1]=1; 
	for(p=2;p<=MS.nu;p++) rpos[p]=rpos[p-1]+nums[p-1];
}

//一般矩阵转置
void transpose(int** M, int** T,int m,int n){
	
	for(int p=0;p<m;p++){
		for(int q=0;q<n;q++){
			T[q][p]=M[p][q];
		}
	} 
} 

//稀疏矩阵转置
void FastTransposeTSMatrix(TSMatrix MS,TSMatrix &TS){
	int rpos[MS.nu+1];
	int q,col;
	if(MS.tu){
		createRpos(MS,rpos);
	
		for(int p=1;p<=MS.tu;p++){
			col=MS.data[p].j; 
			q=rpos[col];
			
			TS.data[q].i=MS.data[p].j;
			TS.data[q].j=MS.data[p].i;
			TS.data[q].e=MS.data[p].e;
			
			++rpos[col];//同一行的下一个非零元的位置加 1 
		
		}//for
	}//if
	
}

//矩阵输出
void coutMat(int** M,int m, int n){
	cout<<"Matrix = "<<endl; 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<M[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
} 

//三元组输出
void coutTSMat(TSMatrix MS){
	
	for(int p=1;p<=MS.tu;p++){
		cout<<"("<<MS.data[p].i<<","<<MS.data[p].j<<","<<MS.data[p].e<<")"<<endl;
	}
	cout<<endl;
}



