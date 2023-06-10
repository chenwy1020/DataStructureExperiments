#include<iostream>
#include<stdlib.h>

using namespace std;

typedef char telemtype;

typedef struct treenode{
	telemtype data;
	treenode *lchild,*rchild; 
}*tree,treenode;

typedef enum {Traval =1,Visit =0} TaskType;
//Traval =1������״̬Ϊ����
//Visit =0������״̬Ϊ���� 

typedef struct{
	tree ptr;
	TaskType task;
}SElemType;

void createtree(tree &T);
void preorder(tree T);
void inorder(tree T);
void nextorder(tree T);
bool treeEmpty(tree T);

int main(){
	tree T;
	cout<<"�밴���������˳�򴴽�������������ڵ�����ӻ��Һ��Ӳ�������ʹ��*���棡�磺��AB*DE***C**��"<<endl;
	createtree(T);
	treeEmpty(T);
	cout<<"��������Ľ��Ϊ:";
	preorder(T);
	cout<<endl;
	cout<<"��������Ľ��Ϊ:";
	inorder(T);
	cout<<endl;
	cout<<"��������Ľ��Ϊ:";
	nextorder(T);
	cout<<endl;
	
	
}

//����������  
void createtree(tree &T){
	char ch;
	cin>>ch;
	//cout<<1<<endl;
	if(ch=='*')	T=NULL;
	else{
		T=new treenode;
		T->data=ch;
		createtree(T->lchild);
		createtree(T->rchild);	
	}
}

//������� ���ݹ飩 
void preorder(tree T){
	if(T){
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//������� ���ݹ飩 
void inorder(tree T){
	if(T){
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}

//������� ���ݹ飩 
void nextorder(tree T){
	if(T){
		nextorder(T->lchild);
		nextorder(T->rchild);
		cout<<T->data<<" ";
	}
}


bool treeEmpty(tree T){
	if(T==NULL){
		cout<<"�ö�����Ϊ��"<<endl; 
		return true;
	}
	else{
		cout<<"�ö�������Ϊ��"<<endl;
		return false;
	}
}



