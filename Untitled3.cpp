//������
//10200115 
#include<iostream>
using namespace std;

//�����ʽ�ĺ�
float polyvalue(float *a,int n,float x){
	float *p=a;
	float xp=1;  //xp���ڴ��x��i�η�
	float sum=0; //���ڴ�Ŷ���ʽ�ĺ�
	for(int i=0;i<=n;i++)     
	{	
		sum+=xp*(*p++);
		xp*=x;
	}
	return sum;
}//polyvalue  

int main(){
	int n;
	cout<<"n = ";
	cin>>n;
	cout<<endl;
	
	float a[n];
	cout<<"a = ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<endl;
	
	float x;
	cout<<"x = ";
	cin>>x;
	cout<<endl;
	cout<<"value = ";
	cout<<polyvalue(a,n,x)<<endl;

}

