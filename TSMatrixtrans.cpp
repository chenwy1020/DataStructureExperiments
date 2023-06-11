//������
//10200115 

//#include"stdafx .h"
#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std; 
const int MAXSIZE=100;
const bool TRUE=1;
const bool FALSE=0; 

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
bool Matrix_Addition(TSMatrix A, TSMatrix B, TSMatrix &C);

 
int main(){
	
	int m=3,n=3;
	int** M=new int*[m];
	int** T=new int*[m];
	TSMatrix MS,TS,QS;
	
	//��ʼ�� 
	for(int i=0;i<m;i++){
		M[i]=new int[n];
		T[i]=new int[n];
	}
	MS.mu=m;	MS.nu=n;
	TS.mu=m;	TS.nu=n;
	for(int p=0;p<m;p++){
		for(int q=0;q<n;q++){
			M[p][q]=0;
			T[p][q]=0;
		}
		M[p][p]=p+1;
		T[p][p]=p+2;
	}
	M[0][n-1]=1;
	T[m-1][0]=1;
	
	//����Ԫ�� ��ʽ�洢
	TSMattrans(M,MS,m,n);
	coutMat(M,m,n);
	cout<<"MSMatrix = "<<endl;
	coutTSMat(MS);
	
	TSMattrans(T,TS,m,n);
	coutMat(T,m,n);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	/*
	//ϡ�����װ�� 
	FastTransposeTSMatrix(MS,TS);
	cout<<"TSMatrix = "<<endl;
	coutTSMat(TS);
	*/
	
	Matrix_Addition(MS,TS,QS);
	cout<<"QSMatrix = "<<endl;
	coutTSMat(QS);
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

// ��Ԫ��洢��ϡ���������㷨: C=A+B 
bool Matrix_Addition(TSMatrix A, TSMatrix B, TSMatrix &C){
	int row_a, row_b,col_a, col_b, index_a, index_b, index_c;
	//AԪ�ص��кţ�BԪ�ص��кţ�AԪ�ص��кţ�BԪ�ص��кţ�ABC������Ԫ��ĵ�ַ
 
	//ͬ���;���������
	if(A.mu!=B.mu || A.nu!=B.nu) return FALSE;
	C.mu = A.mu;	C.nu = A.nu;
 
	//ͬʱ����������Ԫ�飬��ʼ��Ϊ1����Ϊ0λ��δ��Ԫ�أ���A����B����һԪ��ȡ��ѭ����ֹ
	for(index_a=1,index_b=1,index_c=1; index_a<=A.tu&&index_b<=B.tu; ){
		//��ȡ���к� 
		row_a = A.data[index_a].i;	col_a = A.data[index_a].j;
		row_b = B.data[index_b].i;	col_b = B.data[index_b].j;
		
		//���кŷ���ϡ����� 
		if(row_a>row_b){
			//B���к�С ����B��C
			C.data[index_c].i = B.data[index_b].i;
			C.data[index_c].j = B.data[index_b].j;
			C.data[index_c].e = B.data[index_b].e;
			//��󲽽� 
			index_b++;
			index_c++;
		}
		else if(row_a<row_b){
			//A���к�С ����A��C
			C.data[index_c].i = A.data[index_a].i;
			C.data[index_c].j = A.data[index_a].j;
			C.data[index_c].e = A.data[index_a].e;
			//��󲽽� 
			index_a++;
			index_c++;
		}
		else{
			//��ͬ�У���ʼ���кŷ���ϡ����� 
			if(col_a>col_b){
				//B���к�С������B��C
				C.data[index_c].i = B.data[index_b].i;
				C.data[index_c].j = B.data[index_b].j;
				C.data[index_c].e = B.data[index_b].e;
				//��󲽽� 
				index_b++;
				index_c++;
			}
			else if(col_a<col_b){
				//A���к�С������A��C
				C.data[index_c].i = A.data[index_a].i;
				C.data[index_c].j = A.data[index_a].j;
				C.data[index_c].e = A.data[index_a].e;
				//��󲽽� 
				index_a++;
				index_c++;
			}
			else{
				//���к���ͬ ,���ж�Ԫ������Ƿ�Ϊ��
				if((A.data[index_a].e+B.data[index_b].e)){
					C.data[index_c].i = A.data[index_a].i;
					C.data[index_c].j = A.data[index_a].j;
					C.data[index_c].e = A.data[index_a].e + B.data[index_b].e;
					index_c++;
				}
				//��󲽽� 
				index_a++;
				index_b++;
			}
		}
	}
 	//Bȡ��Aδȡ��
	while (index_a <= A.tu){
		C.data[index_c].i = A.data[index_a].i;
		C.data[index_c].j = A.data[index_a].j;
		C.data[index_c].e = A.data[index_a].e;
		index_a++;
		index_c++;
	}
 	//Aȡ��Bδȡ��
	while (index_b <= B.tu){
		C.data[index_c].i = B.data[index_b].i;
		C.data[index_c].j = B.data[index_b].j;
		C.data[index_c].e = B.data[index_b].e;
		index_b++;
		index_c++;
	}
	C.tu = index_c - 1;
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



