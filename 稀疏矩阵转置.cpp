#include<iostream>
#include<string>

using namespace std;

class ju{
	struct shu{
		int i,j;
		int x;
	};
	int m,n;
	int len;
	shu a[25];
	public:
		int juzhen[10][10];
		ju(int o,int p);
		void print()const;
		ju Invert(ju y,ju c);
		void generate();
		void get_three();
};

void ju::get_three()
{
	int i,j;
	int k=1;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(juzhen[i][j]!=0)
			{
				len++;
				a[k].i=i;
				a[k].j=j;
				a[k].x=juzhen[i][j];
				k++;
			}
		}
	}
}

ju::ju(int o,int p)
{
	m=o;
	n=p;
	len=0;
	int j,i;
	cout<<"请输入矩阵的元素：\n";
	for(i=1;i<=o;i++)
	{
		for(j=1;j<=p;j++)
		{
			cin>>juzhen[i][j];
		}
	}
}

void ju::print()const
{
	int i,j,k;
	cout<<"矩阵结果如下：\n";
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<juzhen[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"上述矩阵的三元组表示如下：\n";
	for(k=1;k<=len;k++)
	{
		cout<<a[k].i<<" "<<a[k].j<<" "<<a[k].x<<endl;
	} 
}

void ju:generate()
{
	int k,i,j;
	juzhen[10][10]={0};
	for(k=1;k<=len;k++)
	{
		i=a[k].i;
		j=a[k].j;
		juzhen[i][j]=a[k].x;
	}
}

ju ju::Invert(ju y,ju c)
{
	int a,b;
	int num[20],position[20];
	for(a=1;a<=c.len;a++)
	{
		num[a]=0;
		position[a]=0;
	}
	for(a=1;a<=c.m;a++)
	{
		for(b=1;b<=c.n;b++)
		{
			if(juzhen[b][a]!=0)
			{
				num[b]++;
			}
		}
	}
	position[1]=1;
	for(a=2;a<=len;a++)
	{
		position[a]=num[a-1]+position[a-1];
	}
	for(b=1;b<=c.len;b++)
	{
		int col=c.a[b].j;
		int q=position[col];
		y.a[q].i=c.a[b].j;
		y.a[q].j=c.a[b].i;
		y.a[q].x=c.a[b].x;
		y.len++;
		y.m=c.n;
		y.n=c.m;
		++position[col];
	}
	return y;
}

int main()
{
	int m,n;
	char c;
	
	m=2;n=2;
	
	ju b(m,n);
	b.get_three();
	b.print();
	ju h(m,n);
	h=b.Invert(h,b);
	h.generate();
	h.print();
	
	return 0;
}



