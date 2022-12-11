#include<iostream>
using namespace std;
int f()
{
	return 10;
}
int main(void) {


	f();// <-- ?
	cout << f() << endl;
	//cout << &f() << endl;

	//int& ref = 42; error
	int&& ref = 42;

	cout << ref << endl;
}