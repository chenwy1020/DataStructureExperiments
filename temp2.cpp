#include <iostream>
using namespace std;

class Student
{
public:
	int Age = 18; 
};

class A: public Student{  //非"class A: public Student"即表示私有继承
public:
	int GetAge() { return Age;}  //派生类可以访问基类的public成员
};

int main()
{
	class Student s;
	class A a;
	cout << s.Age << endl;  //可以直接访问基类的public成员
	cout << a.Age << endl;  //无法通过派生类访问基类的public成员（已被继承为private属性）
	cout << a.GetAge ();  //只能通过访问派生类的公有成员间接访问基类
	return 0;
}

