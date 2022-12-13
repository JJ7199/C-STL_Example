#include<iostream>
#include<cstring>
using namespace std;

class String
{
	char buf[100];
public:
	String(const char* sz)
	{
		strcpy_s(buf, sz);
	}
	operator const char* () const
	{
		return buf;
	}
	friend ostream& operator << (ostream& out, const String& str)
	{
		out << str.buf;
		return out;
	}
};

int main()
{
	String s("hello!");
	const char* sz = s;
	cout << s << endl;
	cout << sz << endl;

	return 0;
}