//������
//10200115
 
#include<iostream>
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
	Student stud[num]={	"0001","��   ","172",22,90,
						"0002","��   ","176",22,93,
						"0003","��   ","173",22,92,
						"0004","��   ","183",21,94};
	int i,j,k;
	
	cout<<"��ѧ������"<<endl;
	cout<<"ѧ��"<<"   ";
	cout<<"����"<<"      ";
	cout<<"���"<<"   ";
	cout<<"����"<<"   ";
	cout<<"����"<<endl;
	
	for(i=0; i<num; i++){
		cout<<stud[i].sid<<"   ";
		cout<<stud[i].name<<"     ";
		cout<<stud[i].height<<"    ";
		cout<<stud[i].age<<"     ";
		cout<<stud[i].score<<endl;
	}
	printf("\n"); 
	
	cout<<"���ɼ�����"<<endl;
	cout<<"ѧ��"<<"   ";
	cout<<"����"<<"     ";
	cout<<"���"<<"   ";
	cout<<"����"<<"   ";
	cout<<"����"<<endl;
	
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
		cout<<stud[i].sid<<"   ";
		cout<<stud[i].name<<"    ";
		cout<<stud[i].height<<"    ";
		cout<<stud[i].age<<"     ";
		cout<<stud[i].score<<endl;
	}
	
	return 0;
	
}
