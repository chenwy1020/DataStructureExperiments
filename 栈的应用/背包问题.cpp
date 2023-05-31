//陈文宇
//10200115 
#include"Stack_headerfile.h"

void knapsack(int* w,int T,int n);

int main(){
	
	//顺序栈的操作验证 

	int T=10;
	int w[6]={1,8,4,3,5,2};//背包 
	printf("物品大小：");
	for (int i=0; i<6; i++)
		printf("%d ", *(w + i));
	printf("\n");

	cout<<"全部解在背包的位序"<<endl; 
	knapsack(w,T,6);

}

void knapsack(int* w,int T,int n){
	int k=0;
	SqStack S;
	
	//初始化 
	InitStack_Sq(S,100,10);
	
	
	// 
	while(!StackEmpty_Sq(S) || k<n){

		while(T>0 && k<n){
			if(T-w[k]>=0){
				Push_Sq(S,k);
				T-=w[k];
			}
			k++;
			
		}//while 第k件可选，则入栈 
		
		if(T==0) {
			Stack_Traverse_Sq(S);
			printf("\n");
		}// if 如果为解，则输出解
		
		//栈顶元素出栈，栈顶元素为最后一个可选元素的位序
		//故从第k+1元素开始再次筛选
		//如果后面没有解存在，则再次将栈顶元素出栈 
		Pop_Sq(S,k);
		T+=w[k];
		k++;
		
	}//while
		
}





