#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;

class String
{
	char buff[100];
public:
	String(const char* sz)
	{
		strcpy(buff, sz);
	}

	void Print() const
	{
		cout << buff << endl;
	}
	friend ostream& operator << (ostream& out, const String& str)
	{
		out << str.buff;
		return out;
	}
};

int main()
{
	const char* sz = "Hello";
	String s("hi~!");

	s = sz;
	s.Print();
	cout << sz << endl;
	cout << s << endl;

	return 0;
}