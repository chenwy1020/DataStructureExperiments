#include<iostream>
#include<stdlib.h>

using namespace std;

typedef char telemtype;

typedef struct treenode{
	telemtype data;
	treenode *lchild,*rchild; 
}*tree,treenode;

typedef enum {Traval =1,Visit =0} TaskType;
//Traval =1：工作状态为遍历
//Visit =0：工作状态为访问 

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
	cout<<"请按先序遍历的顺序创建二叉树，若其节点的左孩子或右孩子不存在则使用*代替！如：（AB*DE***C**）"<<endl;
	createtree(T);
	treeEmpty(T);
	cout<<"先序遍历的结果为:";
	preorder(T);
	cout<<endl;
	cout<<"中序遍历的结果为:";
	inorder(T);
	cout<<endl;
	cout<<"后序遍历的结果为:";
	nextorder(T);
	cout<<endl;
	
	
}

//创建二叉树  
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

//先序遍历 （递归） 
void preorder(tree T){
	if(T){
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//中序遍历 （递归） 
void inorder(tree T){
	if(T){
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}

//后序遍历 （递归） 
void nextorder(tree T){
	if(T){
		nextorder(T->lchild);
		nextorder(T->rchild);
		cout<<T->data<<" ";
	}
}


bool treeEmpty(tree T){
	if(T==NULL){
		cout<<"该二叉树为空"<<endl; 
		return true;
	}
	else{
		cout<<"该二叉树不为空"<<endl;
		return false;
	}
}



