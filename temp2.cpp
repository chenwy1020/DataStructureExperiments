#include <iostream>
using namespace std;

class Student
{
public:
	int Age = 18; 
};

class A: public Student{  //��"class A: public Student"����ʾ˽�м̳�
public:
	int GetAge() { return Age;}  //��������Է��ʻ����public��Ա
};

int main()
{
	class Student s;
	class A a;
	cout << s.Age << endl;  //����ֱ�ӷ��ʻ����public��Ա
	cout << a.Age << endl;  //�޷�ͨ����������ʻ����public��Ա���ѱ��̳�Ϊprivate���ԣ�
	cout << a.GetAge ();  //ֻ��ͨ������������Ĺ��г�Ա��ӷ��ʻ���
	return 0;
}

