//������
//10200115 
#include"Stack_headerfile.h"

void knapsack(int* w,int T,int n);

int main(){
	
	//˳��ջ�Ĳ�����֤ 

	int T=10;
	int w[6]={1,8,4,3,5,2};//���� 
	printf("��Ʒ��С��");
	for (int i=0; i<6; i++)
		printf("%d ", *(w + i));
	printf("\n");

	cout<<"ȫ�����ڱ�����λ��"<<endl; 
	knapsack(w,T,6);

}

void knapsack(int* w,int T,int n){
	int k=0;
	SqStack S;
	
	//��ʼ�� 
	InitStack_Sq(S,100,10);
	
	
	// 
	while(!StackEmpty_Sq(S) || k<n){

		while(T>0 && k<n){
			if(T-w[k]>=0){
				Push_Sq(S,k);
				T-=w[k];
			}
			k++;
			
		}//while ��k����ѡ������ջ 
		
		if(T==0) {
			Stack_Traverse_Sq(S);
			printf("\n");
		}// if ���Ϊ�⣬�������
		
		//ջ��Ԫ�س�ջ��ջ��Ԫ��Ϊ���һ����ѡԪ�ص�λ��
		//�ʴӵ�k+1Ԫ�ؿ�ʼ�ٴ�ɸѡ
		//�������û�н���ڣ����ٴν�ջ��Ԫ�س�ջ 
		Pop_Sq(S,k);
		T+=w[k];
		k++;
		
	}//while
		
}





