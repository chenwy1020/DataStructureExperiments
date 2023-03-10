#include<iostream>;
#define num 4
using namespace std;

struct Student{
	char sid[5];
	char name[10];
	char height[10]; 
	int age;
	int score;
};

int main(){
	Student temp;
	Student stud[num]={"0001","陈文宇","172",22,90,"0002","高鹏智","176",22,93,"0003","吴硕龙","173",22,92,"0004","刘小端","183",21,94};
	int i,j,k;
	
	cout<<"按学号排序"<<endl;
	cout<<"学号"<<"   "<<"姓名"<<"       "<<"身高"<<"   "<<"年龄"<<"   "<<"分数"<<endl;
	
	for(i=0; i<num; i++){
		cout<<stud[i].sid<<"   "<<stud[i].name<<"     "<<stud[i].height<<"    "<<stud[i].age<<"     "<<stud[i].score<<endl;
	}
	printf("\n"); 
	
	cout<<"按成绩排序"<<endl;
	cout<<"学号"<<"   "<<"姓名"<<"       "<<"身高"<<"   "<<"年龄"<<"   "<<"分数"<<endl;
	
	for(i=0; i<num; i++){
		j=i;
		for(k=i; k<num; k++){
			if(stud[k].score > stud[j].score){
				j=k;
			}
		}
		temp=stud[i];
		stud[i]=stud[j];
		stud[j]=temp;
	}
	for(i=0; i<num; i++){
		cout<<stud[i].sid<<"   "<<stud[i].name<<"     "<<stud[i].height<<"    "<<stud[i].age<<"     "<<stud[i].score<<endl;
	}
	
	return 0;
	
}
