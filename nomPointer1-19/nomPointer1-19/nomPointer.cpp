#include<iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	
};

class PointPtr
{
	Point* ptr;
public:
	PointPtr(Point *p): ptr(p){ }
	~PointPtr()
	{
		delete ptr;
	}
	Point* operator->() const
	{
		return ptr;
	}
	Point& operator* () const // * 연산자는 포인터가 가르키는 객체 그 자체 
	{
		return *ptr;
	}
};

int main()
{
	//Point* p1 = new Point(2, 3); //메모리 할당
	//Point* p2 = new Point(5, 5);

	//p1->Print();
	//p2->Print();

	//delete p1; //메모리 제거
	//delete p2;
	//PointPtr p1 = new Point(2, 3); // 메모리 할당
	//PointPtr p2 = new Point(5, 5);

	//p1->Print();
	//p2->Print();

	// 소멸자에서 동적객체를 자동으로 메모리에서 제거
	Point* p1 = new Point(2, 3); //메모리 할당, 일반 포인터
	PointPtr p2 = new Point(5, 5); // 스마트 포인터

	p1->Print();
	p2->Print(); //p2.operator->()->Print() 호출

	(*p1).Print();
	(*p2).Print();//p2.operator*().Print() 호출

	delete p1;

	return 0;
}