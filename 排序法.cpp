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
void Msort(RcdType SR[], RcdType TR1[], int s,int t,int n);
void MergeSort(SqList &L);

void MaxHead(SqList &L,int s,int t);
void HeadSort(SqList &L);

void RadixPass1(RcdType A[],RcdType B[],int n);
void RadixPass2(RcdType A[],RcdType B[],int n);
void RadixSort(SqList &L);


void counting_sort(RcdType A[], RcdType B[], int n, int m);
void CountingSort(SqList &L);

void ShellSort(SqList &L);

int main(){
	int n=12,m=8;
	SqList* A;
	A=(SqList*)malloc(sizeof(SqList)*n); 
	for(int i=0;i<n;i++){
		A[i].length=m;
		A[i].r[1].key=49;
		A[i].r[2].key=38;
		A[i].r[3].key=65;
		A[i].r[4].key=49;
		A[i].r[5].key=76;
		A[i].r[6].key=13;
		A[i].r[7].key=27;
		A[i].r[8].key=52;
	}
	
	//------------------------------------------------------- 
	printf("ѡ������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[0].r[i].key<<"  "<<endl;
	}
	SelectSort(A[0]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[0].r[i].key<<"  "<<endl;
	}
	
	
	//-------------------------------------------------------- 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[1].r[i].key<<"  "<<endl;
	}
	InsertSort(A[1]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[1].r[i].key<<"  "<<endl;
	}
	
	//------------------------------------------------------- 
	printf("\n\n\nð������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[2].r[i].key<<"  "<<endl;
	}
	BubbleSort(A[2]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[2].r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------------------- 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[3].r[i].key<<"  "<<endl;
	}
	QuickSort(A[3]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[3].r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------ 
	printf("\n\n\n�鲢����\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[4].r[i].key<<"  "<<endl;
	}
	MergeSort(A[4]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[4].r[i].key<<"  "<<endl;
	}
	
	//------------------------------------------ 
	printf("\n\n\n������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[5].r[i].key<<"  "<<endl;
	}
	HeadSort(A[5]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[5].r[i].key<<"  "<<endl;
	}
	
	//------------------------------------------ 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[6].r[i].key<<"  "<<endl;
	}
	RadixSort(A[6]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[6].r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------ 
	printf("\n\n\n��������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[7].r[i].key<<"  "<<endl;
	}
	CountingSort(A[7]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[7].r[i].key<<"  "<<endl;
	}
	
	
	//------------------------------------------ 
	printf("\n\n\nϣ������\n");
	cout<<"����ǰ"<<endl; 
	for(int i=1;i<=m; i++){
		cout<<A[8].r[i].key<<"  "<<endl;
	}
	ShellSort(A[8]);
	cout<<"�����"<<endl;
	for(int i=1;i<=m; i++){
		cout<<A[8].r[i].key<<"  "<<endl;
	}
	
	free(A);
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
	for(k=i; i<=m && j<=n; k++){
		if(SR[i].key<=SR[j].key) TR[k]=SR[i++];
		else TR[k]=SR[j++];
	}//for
	while(i<=m) TR[k++]=SR[i++];
	while(j<=n) TR[k++]=SR[j++];
	
} //Merge

void Msort(RcdType SR[], RcdType TR1[], int s,int t,int n){
	RcdType TR2[n];
	int m;
	if(s==t) TR1[s]=SR[s];
	else{
		m=(s+t)/2;
		Msort(SR,TR2,s,m,n);
		Msort(SR,TR2,m+1,t,n);
		Merge(TR2,TR1,s,m,t);
	}//else
	
}//Msort

void MergeSort(SqList &L){
	Msort(L.r, L.r, 1, L.length,L.length+1);
}//MergeSort


//������(��������ѡ������)
void MaxHead(SqList &L,int s,int t){
	int dad=s;
	int son=2*s;
	RcdType temp;
	while(son<=t){
		if(son+1<=t && L.r[son].key<L.r[son+1].key) son++;
		if(L.r[dad].key>L.r[son].key) return;
		else{
			temp=L.r[dad]; L.r[dad]=L.r[son]; L.r[son]=temp;
			dad=son;
			son=2*dad;
		} 
	}//while
	
}//MaxHead

void HeadSort(SqList &L){
	RcdType temp;
	//��������
	for(int i=L.length/2;i>=1;i--)
		MaxHead(L,i,L.length);
	
	//�ѵ��� 
	for(int i=L.length;i>1;i--){
		temp=L.r[i]; L.r[i]=L.r[1]; L.r[1]=temp;
		MaxHead(L,1,i-1);
	}//for
}//HeadSort

//��������
void RadixPass1(RcdType A[],RcdType B[],int n){
	int count[10];
	int j,k;
	for(j=0;j<10;j++) count[j]=0;
	for(k=1;k<=n;k++) count[A[k].key % 10] ++;
	for(j=1;j<10;j++) count[j]=count[j-1]+count[j];
	for(k=n;k>=1;k--){
		j=A[k].key % 10;
		B[count[j]]=A[k];
		count[j]--;
	}//for
	
}//RadixPass1

void RadixPass2(RcdType A[],RcdType B[],int n){
	int count[10];
	int j,k;
	for(j=0;j<10;j++) count[j]=0;
	for(k=1;k<=n;k++) count[A[k].key/10] ++;
	for(j=1;j<10;j++) count[j]=count[j-1]+count[j];
	for(k=n;k>=1;k--) B[count[A[k].key/10]--]=A[k];

}//RadixPass2

void RadixSort(SqList &L){
	RcdType C[L.length+1];
	
	RadixPass1(L.r, C, L.length);
	
	RadixPass2(C, L.r, L.length);
	
} //RadixSort

//��������
//��Ҫ֪���ؼ��ֵķ�Χ 
//ʵ���ϼ���������Կ������������һ���ӹ��� �������ؼ���ֻ��һ�� 
void counting_sort(RcdType A[], RcdType B[], int n, int m) {
	//��ʾ m ��ʾ��Χ ,n ��ʾ����Ԫ�ظ��� 
    int *count= (int*) malloc(sizeof(int)*m);
 
    for (int i=0; i<m; i++)
        count[i] = 0;
        
    for (int i=1; i<=n; i++)
        count[A[i].key]++;
        
    for (int i= 1; i<m; i++)
        count[i] += count[i-1];
        
    for (int i=n; i>=1; i--)
        B[count[A[i].key]--].key = A[i].key;
    free(count);
}

void CountingSort(SqList &L){
	int m=100;
	RcdType* B=(RcdType*)malloc(sizeof(RcdType)*(L.length+1));
	counting_sort(L.r,B,L.length,m);
	for(int i=1;i<=L.length;i++)
		L.r[i]=B[i];	
	free(B);
} 



//ϣ������(���ڲ�������) 
void ShellSort(SqList &L){
	int d=L.length/2;
	int k;
	RcdType temp;
	while(d){
		for(int i=1;i<=d;i++){//ȷ������ Ϊ i ������ 
			for(int j=1; i+j*d<=L.length; j++){//�������н����о� 
			
				if(L.r[i+j*d].key < L.r[i+(j-1)*d].key) {//�ӵ�һ������ʼ 

					L.r[0]=L.r[i+j*d]; //ȷ�������еĵ�j �� 
					for(k=j-1; L.r[0].key < L.r[i+k*d].key && k>=0; k--)
							L.r[i+(k+1)*d]=L.r[i+k*d];		
					L.r[i+(k+1)*d]=L.r[0];
				}//if
			}
		
		}//for
		d=d/2;
	}//while
	

}

//˫������(Bitonicsort) 


//Ͱ���� 


//��λ������(BFPRT����) 




