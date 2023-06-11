//陈文宇
//10200115 
#include<iostream>
using namespace std;

//求多项式的和
float polyvalue(float *a,int n,float x){
	float *p=a;
	float xp=1;  //xp用于存放x的i次方
	float sum=0; //用于存放多项式的和
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

