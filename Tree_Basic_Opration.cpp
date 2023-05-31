//陈文宇
//10200115 

//#include"stdafx .h"
#include<iostream>
using namespace std; 

typedef  char TElemType;
const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;

void CreatebiTree(BiTree &T);
void Preorder(BiTree T, void (*visit)(BiTree T));
void Midorder(BiTree T, void (*visit)(BiTree T));
void Behorder(BiTree T, void (*visit)(BiTree T));
void *visit(BiTree T);

int main(){
	
	BiTree T;
	CreatebiTree(T); 
	Preorder(T, void (*visit)(BiTree T));
	
}


//创建二叉树 
void CreatebiTree(BiTree &T){
	TElemType ch; 
	cin>>ch;
	if(ch=='#')T=NULL;
	else{
		T=new BiTNode;
		T->data=ch;
		CreatebiTree(T->lchild);
		CreatebiTree(T->rchild);
	}
	
}CreatebiTree


//先序变历 
void Preorder(BiTree T, void (*visit)(BiTree T)){
	if(T){
		visit(T);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
}

//中序变历 
void Midorder(BiTree T, void (*visit)(BiTree T)){
	if(T){
		Midorder(T->lchild,visit);
		visit(T);
		Midorder(T->rchild,visit);
	}
}

//后序变历 
void Behorder(BiTree T, void (*visit)(BiTree T)){
	if(T){
		Behorder(T->lchild,visit);
		Behorder(T->rchild,visit);
		visit(T);
	}
}

void *visit(BiTree T){
	if(T) cout<<T;
}







