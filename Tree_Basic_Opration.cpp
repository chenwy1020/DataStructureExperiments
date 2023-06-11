//陈文宇
//10200115 
#include<iostream>
#include<stack> 

using namespace std; 
const int LISTINIT_SIZE=100;
const int LISTINCREMENT=10;
const bool TRUE=1;
const bool FALSE=0; 
const int PLUS=-1;
const int MINUS=-2;
const int ASTERISK=-3;
const int SLANT=-4;
 
//二叉树定义 
typedef  char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef enum {Travel =1,Visit =0} TaskType;
//Traval =1：工作状态为遍历
//Visit =0：工作状态为访问 

typedef struct{
	BiTree ptr; 	//指向二叉树结点的指针 
	TaskType task;	//任务的性质 
}SElemType; 		//栈元素的类型定义 

typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	struct BiThrNode *pred,*succ;
}BiThrNode,*BiThrTree; 

void CreatebiTree(BiTree &T);
void BiTreeDepth(BiTree T,int h,int &depth);
int Get_Depth(BiTree T);
BiTNode *GetTreeNode(TElemType iten,BiTNode *lptr,BiTNode *rptr);
int Get_Sub_Depth(BiTree T,TElemType x, int &depth); 
int LeafCount(BiTree T);
BiTNode *CopyTree(BiTree T);
double value(BiTree T,float *opnd);

void Preorder(BiTree T, void (*visit)(BiTree T));
void Inorder(BiTree T, void (*visit)(BiTree T));
void Nextorder(BiTree T, void (*visit)(BiTree T));

void Preorder_iter(BiTree T, void (*visit)(BiTree));
void Inorder_iter(BiTree T, void (*visit)(BiTree));
void Nextorder_iter(BiTree T, void (*visit)(BiTree));

void Inorder(BiThrTree H,void(*visit)(BiTree));
void InThreading(BiThrTree p,BiThrTree &T);
void InorderThreading(BiThrTree &H,BiThrTree T);

void visit(BiTree T);
void visit2(BiThrTree T);

int main(){
	
	BiTree T,S,V;
	
	//----------------------------------------------------
	cout<<"请按先序遍历的顺序创建二叉树，若其节点的左孩子或右孩子不存在则使用*代替！如：（AB#DE###C##）"<<endl;
	CreatebiTree(T); 
	cout<<"先序遍历( 递归 )的结果为:";
	Preorder(T, visit);
	cout<<endl;
	cout<<"中序遍历( 递归 )的结果为:";
	Inorder(T, visit);
	cout<<endl;
	cout<<"后序遍历( 递归 )的结果为:";
	Nextorder(T, visit);
	cout<<endl;
	
	cout<<"先序遍历(非递归)的结果为:";
	Preorder_iter(T, visit);
	cout<<endl;
	cout<<"中序遍历(非递归)的结果为:";
	Inorder_iter(T, visit);
	cout<<endl;
	cout<<"后序遍历(非递归)的结果为:";
	Nextorder_iter(T, visit);
	cout<<endl;
	cout<<endl;
	//----------------------------------------------------
	//树的深度
	int h=1,depth=0;
	BiTreeDepth(T,h,depth);
	cout<<"树的深度为："<<depth<<endl;
	cout<<endl;

	//二叉树的叶子结点个数
	cout<<"叶子结点个数:";
	cout<<LeafCount(T)<<endl;
	cout<<endl;
	
	//条件子树的深度
	cout<<"以X为根的树的深度："; 
	Get_Sub_Depth(T,'B',depth);
	cout<<depth<<endl;
	cout<<endl;
	

	//----------------------------------------------------
	//复制一棵二叉树
	S=CopyTree(T);
	cout<<"复制二叉树的结果为:";
	Preorder(S, visit);
	cout<<endl;
	cout<<endl;
	
	
	
	/*
	//----------------------------------------------------
	//表达式求值
	CreatebiTree(V);
	cout<<"先序遍历( 递归 )的结果为:";
	Preorder(V, visit);
	cout<<endl;
	float opnd[7]={0,3.4,4.7,29.2,61.5,3.14,1.41};
	
	
	cout<<value(V,opnd)<<endl;
	*/
	
	
}


//二叉链表创建二叉树 
void CreatebiTree(BiTree &T){
	TElemType ch; 
	cin>>ch;
	if(ch=='#')T=NULL;//使用整型时请用 0 代替 
	else{
		T=new BiTNode;
		T->data=ch;
		CreatebiTree(T->lchild);
		CreatebiTree(T->rchild);
	}
	
}//CreatebiTree

//求二叉树的深度
void BiTreeDepth(BiTree T,int h,int &depth){
	//h的初值为 1，depth的初值为 0 
	//h 指向结点所在的层,depth是深度 
	if(T){
		if(h>depth) depth=h;
		BiTreeDepth(T->lchild,h+1,depth);
		BiTreeDepth(T->rchild,h+1,depth);
	}
}//BiTreeDepth

//求子树深度的递归算法
int Get_Depth(BiTree T) {
	int m,n;
	if(!T)  
		return 0;
	else {
		m=Get_Depth(T->lchild);     
		n=Get_Depth(T->rchild);    
		return (m>n?m:n)+1;   
	}
} //Get_Depth 



int Get_Sub_Depth(BiTree T,TElemType x, int &depth){

	if(T->data==x){
		depth=Get_Depth(T); 
		return 0;
	}
	else{
		if(T->lchild)  
			Get_Sub_Depth(T->lchild,x,depth);   
		if(T->rchild) 
			Get_Sub_Depth(T->rchild,x,depth); 
   }  
}

//求二叉树中叶子结点的数目
int LeafCount(BiTree T){
	if(!T)  return 0; 
	else if(!T->lchild && !T->rchild) 
    	return 1; 
	else return LeafCount(T->lchild)+LeafCount(T->rchild);

} //LeafCount

//复制一棵二叉树
//复制左右子树，组装为树 
BiTNode *GetTreeNode(TElemType item,BiTNode *lptr,BiTNode *rptr){
	BiTNode *T;
	T=new BiTNode;
	T->data=item;
	T->lchild=lptr;
	T->rchild=rptr;
} 

BiTNode *CopyTree(BiTree T){
	BiTree newlptr,newrptr,newnode;
	
	if(!T) return NULL;
	if(T->lchild) newlptr=CopyTree(T->lchild);
	else newlptr=NULL;
	if(T->rchild) newrptr=CopyTree(T->rchild);
	else newrptr=NULL;
	newnode=GetTreeNode(T->data,newlptr,newrptr);
	return newnode;
}

//表达式求值
double value(BiTree T,float *opnd){
	double Lv,Rv,v;
	if(!T) return 0;
	if(T->data>=0) return opnd[T->data];
	Lv=value(T->lchild,opnd);
	Rv=value(T->rchild,opnd);
	switch(T->data){
		case PLUS: 		{v=Lv+Rv;	break;}
		case MINUS:		{v=Lv-Rv;	break;}
		case ASTERISK:	{v=Lv*Rv;	break;}
		case SLANT:		{v=Lv/Rv;	break;}
		default:		cout<<"不合法的运算"<<endl;
	}//switch
	return v;
}

//先序遍历 （递归） 
void Preorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		visit(T);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
}

//中序变历 （递归） 
void Inorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Inorder(T->lchild,visit);
		visit(T);
		Inorder(T->rchild,visit);
	}
}

//后序变历 （递归） 
void Nextorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Nextorder(T->lchild,visit);
		Nextorder(T->rchild,visit);
		visit(T);
	}
}

//先序变历 （非递归） 
void Preorder_iter(BiTree T, void (*visit)(BiTree)){
	stack<SElemType> s;
	SElemType e;
	BiTree p;
	
	e.task=Travel; e.ptr=T;
	if(T) s.push(e);
	while(!s.empty()){
		e=s.top();
		s.pop();
		if(e.task==Visit) visit(e.ptr);
		else{
			if(e.ptr){									  //处理非空树的遍历任务 
				p=e.ptr;
				e.ptr=p->rchild; e.task=Travel;s.push(e); //最不迫切任务
				e.ptr=p->lchild; e.task=Travel;s.push(e); //迫切任务进栈 
				e.ptr=p; 		 e.task=Visit; s.push(e); //处理访问任务的工作状态和结点指针进栈 
			}//if 
		}//else
	}//while 
	
}//Preorder_iter

//中序变历 （非递归） 
void Inorder_iter(BiTree T, void (*visit)(BiTree)){
	stack<SElemType> s;
	SElemType e;
	BiTree p;
	
	e.task=Travel; e.ptr=T;
	if(T) s.push(e);
	while(!s.empty()){
		e=s.top();
		s.pop();
		if(e.task==Visit) visit(e.ptr);
		else{
			if(e.ptr){									  //处理非空树的遍历任务 
				p=e.ptr;
				e.ptr=p->rchild; e.task=Travel;s.push(e); //最不迫切任务
				e.ptr=p; 		 e.task=Visit; s.push(e); //处理访问任务的工作状态和结点指针进栈 
				e.ptr=p->lchild; e.task=Travel;s.push(e); //迫切任务进栈 
			}//if 
		}//else
	}//while 
	
}//Inorder_iter

//后序变历 （非递归） 
void Nextorder_iter(BiTree T, void (*visit)(BiTree)){
	stack<SElemType> s;
	SElemType e;
	BiTree p;
	
	e.task=Travel; e.ptr=T;
	if(T) s.push(e);
	while(!s.empty()){
		e=s.top();
		s.pop();
		if(e.task==Visit) visit(e.ptr);
		else{
			if(e.ptr){									  //处理非空树的遍历任务 
				p=e.ptr;
				e.ptr=p; 		 e.task=Visit;  s.push(e); //处理访问任务的工作状态和结点指针进栈 
				e.ptr=p->rchild; e.task=Travel; s.push(e); //最不迫切任务
				e.ptr=p->lchild; e.task=Travel; s.push(e); //迫切任务进栈 
			}//if 
		}//else
	}//while 
	
}//Nextorder_iter

//访问函数 
void visit(BiTree T){
	if(T) cout<<T->data<<" ";
}

void visit2(BiThrTree T){
	if(T) cout<<T->data<<" ";
}

bool treeEmpty(BiTree T){
	if(T==NULL){
		cout<<"该二叉树为空"<<endl; 
		return TRUE;
	}
	else{
		cout<<"该二叉树不为空"<<endl;
		return FALSE;
	}
}

//全线索链表的中序遍历算法 
void Inorder(BiThrTree H,void (*visit2)(BiThrTree)){
	BiThrNode *p;
	p=H->succ;
	while(p!=H){
		visit2(p);
		p=p->succ;
	}
}

//中序遍历线索化 
void InorderThreading(BiThrTree &H,BiThrTree T){
	BiThrNode *pre;
	H=new BiThrNode;
	H->lchild=T; H->rchild=NULL;
	if(!T){
		InThreading(T,pre);
		pre->succ=H;
		H->pred=pre;
	}
} 

void InThreading(BiThrTree p,BiThrTree &T){
	BiThrNode *pre;
	if(p){
		InThreading(p->lchild,pre);
		pre->succ=p; p->pred=pre;
		pre=p;
		InThreading(p->rchild,pre);
	}
}



