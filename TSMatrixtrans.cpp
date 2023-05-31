//������
//10200115 

//#include"stdafx .h"
#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std; 
const int MAXSIZE=100;

typedef int ElemType;
 
typedef struct{
	int i,j;				//����Ԫ�����±�����±� 
	ElemType e;				//�÷���Ԫ��Ԫ��ֵ 
}Triple;
typedef struct{
	Triple data[MAXSIZE];	//����Ԫ��Ԫ���data[0]δ��
	int mu,nu,tu;			//ϡ�����������������ͷ���Ԫ����
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
	
	//��ʼ�� 
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
	
	//����Ԫ�� ��ʽ�洢
	TSMattrans(M,MS,m,n);
	coutMat(M,m,n);
	cout<<"MSMatrix = "<<endl;
	coutTSMat(MS);
	
	//һ�����ת��
	transpose(M,T,m,n);
	TSMattrans(T,TS,m,n);
	coutMat(T,m,n);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	
	//ϡ�����װ�� 
	FastTransposeTSMatrix(MS,TS);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	
	
	
	//���پ��� 
	for(int p=0;p<m;p++){
		delete[] M[p];
		delete[] T[p];
	}
	delete[] M;
	delete[] T;
	
	
}
//����¼��ϡ����� ������Ԫ�� ��ʽ�洢 
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

//num[] ������  rops[] ������ 
void createRpos(TSMatrix MS,int* rpos){
	int nums[MS.nu+1];
	int p;
	//rops �� M ��ÿһ�еĵ�һ������Ԫ ��T.data �е����   ��Ϊλ����
	//nums �� M ��ÿһ�еķ���Ԫ�ĸ��� 
	for(p=1;p<=MS.nu;p++) nums[p]=0;
	for(p=1;p<=MS.tu;p++) nums[MS.data[p].j]++;
	rpos[1]=1; 
	for(p=2;p<=MS.nu;p++) rpos[p]=rpos[p-1]+nums[p-1];
}

//һ�����ת��
void transpose(int** M, int** T,int m,int n){
	
	for(int p=0;p<m;p++){
		for(int q=0;q<n;q++){
			T[q][p]=M[p][q];
		}
	} 
} 

//ϡ�����ת��
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
			
			++rpos[col];//ͬһ�е���һ������Ԫ��λ�ü� 1 
		
		}//for
	}//if
	
}

//�������
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

//��Ԫ�����
void coutTSMat(TSMatrix MS){
	
	for(int p=1;p<=MS.tu;p++){
		cout<<"("<<MS.data[p].i<<","<<MS.data[p].j<<","<<MS.data[p].e<<")"<<endl;
	}
	cout<<endl;
}



