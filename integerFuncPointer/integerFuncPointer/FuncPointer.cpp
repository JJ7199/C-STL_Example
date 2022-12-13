#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "Á¤¼ö : " << n << endl;
}

int main()
{
	void (*pf) (int);

	pf = Print;

	Print(10);
	pf(20);
	(*pf)(30);

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;

	return 0;
}