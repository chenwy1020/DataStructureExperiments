//������
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
 
//���������� 
typedef  char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef enum {Travel =1,Visit =0} TaskType;
//Traval =1������״̬Ϊ����
//Visit =0������״̬Ϊ���� 

typedef struct{
	BiTree ptr; 	//ָ�����������ָ�� 
	TaskType task;	//��������� 
}SElemType; 		//ջԪ�ص����Ͷ��� 

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
	cout<<"�밴���������˳�򴴽�������������ڵ�����ӻ��Һ��Ӳ�������ʹ��*���棡�磺��AB#DE###C##��"<<endl;
	CreatebiTree(T); 
	cout<<"�������( �ݹ� )�Ľ��Ϊ:";
	Preorder(T, visit);
	cout<<endl;
	cout<<"�������( �ݹ� )�Ľ��Ϊ:";
	Inorder(T, visit);
	cout<<endl;
	cout<<"�������( �ݹ� )�Ľ��Ϊ:";
	Nextorder(T, visit);
	cout<<endl;
	
	cout<<"�������(�ǵݹ�)�Ľ��Ϊ:";
	Preorder_iter(T, visit);
	cout<<endl;
	cout<<"�������(�ǵݹ�)�Ľ��Ϊ:";
	Inorder_iter(T, visit);
	cout<<endl;
	cout<<"�������(�ǵݹ�)�Ľ��Ϊ:";
	Nextorder_iter(T, visit);
	cout<<endl;
	cout<<endl;
	//----------------------------------------------------
	//�������
	int h=1,depth=0;
	BiTreeDepth(T,h,depth);
	cout<<"�������Ϊ��"<<depth<<endl;
	cout<<endl;

	//��������Ҷ�ӽ�����
	cout<<"Ҷ�ӽ�����:";
	cout<<LeafCount(T)<<endl;
	cout<<endl;
	
	//�������������
	cout<<"��XΪ����������ȣ�"; 
	Get_Sub_Depth(T,'B',depth);
	cout<<depth<<endl;
	cout<<endl;
	

	//----------------------------------------------------
	//����һ�ö�����
	S=CopyTree(T);
	cout<<"���ƶ������Ľ��Ϊ:";
	Preorder(S, visit);
	cout<<endl;
	cout<<endl;
	
	
	
	/*
	//----------------------------------------------------
	//���ʽ��ֵ
	CreatebiTree(V);
	cout<<"�������( �ݹ� )�Ľ��Ϊ:";
	Preorder(V, visit);
	cout<<endl;
	float opnd[7]={0,3.4,4.7,29.2,61.5,3.14,1.41};
	
	
	cout<<value(V,opnd)<<endl;
	*/
	
	
}


//���������������� 
void CreatebiTree(BiTree &T){
	TElemType ch; 
	cin>>ch;
	if(ch=='#')T=NULL;//ʹ������ʱ���� 0 ���� 
	else{
		T=new BiTNode;
		T->data=ch;
		CreatebiTree(T->lchild);
		CreatebiTree(T->rchild);
	}
	
}//CreatebiTree

//������������
void BiTreeDepth(BiTree T,int h,int &depth){
	//h�ĳ�ֵΪ 1��depth�ĳ�ֵΪ 0 
	//h ָ�������ڵĲ�,depth����� 
	if(T){
		if(h>depth) depth=h;
		BiTreeDepth(T->lchild,h+1,depth);
		BiTreeDepth(T->rchild,h+1,depth);
	}
}//BiTreeDepth

//��������ȵĵݹ��㷨
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

//���������Ҷ�ӽ�����Ŀ
int LeafCount(BiTree T){
	if(!T)  return 0; 
	else if(!T->lchild && !T->rchild) 
    	return 1; 
	else return LeafCount(T->lchild)+LeafCount(T->rchild);

} //LeafCount

//����һ�ö�����
//����������������װΪ�� 
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

//���ʽ��ֵ
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
		default:		cout<<"���Ϸ�������"<<endl;
	}//switch
	return v;
}

//������� ���ݹ飩 
void Preorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		visit(T);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
}

//������� ���ݹ飩 
void Inorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Inorder(T->lchild,visit);
		visit(T);
		Inorder(T->rchild,visit);
	}
}

//������� ���ݹ飩 
void Nextorder(BiTree T, void (*visit)(BiTree)){
	if(T){
		Nextorder(T->lchild,visit);
		Nextorder(T->rchild,visit);
		visit(T);
	}
}

//������� ���ǵݹ飩 
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
			if(e.ptr){									  //����ǿ����ı������� 
				p=e.ptr;
				e.ptr=p->rchild; e.task=Travel;s.push(e); //���������
				e.ptr=p->lchild; e.task=Travel;s.push(e); //���������ջ 
				e.ptr=p; 		 e.task=Visit; s.push(e); //�����������Ĺ���״̬�ͽ��ָ���ջ 
			}//if 
		}//else
	}//while 
	
}//Preorder_iter

//������� ���ǵݹ飩 
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
			if(e.ptr){									  //����ǿ����ı������� 
				p=e.ptr;
				e.ptr=p->rchild; e.task=Travel;s.push(e); //���������
				e.ptr=p; 		 e.task=Visit; s.push(e); //�����������Ĺ���״̬�ͽ��ָ���ջ 
				e.ptr=p->lchild; e.task=Travel;s.push(e); //���������ջ 
			}//if 
		}//else
	}//while 
	
}//Inorder_iter

//������� ���ǵݹ飩 
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
			if(e.ptr){									  //����ǿ����ı������� 
				p=e.ptr;
				e.ptr=p; 		 e.task=Visit;  s.push(e); //�����������Ĺ���״̬�ͽ��ָ���ջ 
				e.ptr=p->rchild; e.task=Travel; s.push(e); //���������
				e.ptr=p->lchild; e.task=Travel; s.push(e); //���������ջ 
			}//if 
		}//else
	}//while 
	
}//Nextorder_iter

//���ʺ��� 
void visit(BiTree T){
	if(T) cout<<T->data<<" ";
}

void visit2(BiThrTree T){
	if(T) cout<<T->data<<" ";
}

bool treeEmpty(BiTree T){
	if(T==NULL){
		cout<<"�ö�����Ϊ��"<<endl; 
		return TRUE;
	}
	else{
		cout<<"�ö�������Ϊ��"<<endl;
		return FALSE;
	}
}

//ȫ�����������������㷨 
void Inorder(BiThrTree H,void (*visit2)(BiThrTree)){
	BiThrNode *p;
	p=H->succ;
	while(p!=H){
		visit2(p);
		p=p->succ;
	}
}

//������������� 
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



