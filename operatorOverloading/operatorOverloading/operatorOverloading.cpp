#include<iostream>
using namespace std;

class Point
{
	int x;
	int y;

public:
	Point(int _x = 0 , int _y = 0) : x(_x),y(_y) {}
	int GetX() const { return x; }
	int GetY() const { return y; }
	void Print() const { cout << x << ',' << ' ' << y << endl; }

	friend const Point& operator-(const Point& argL, const Point& argR);

	const Point operator+(const Point& arg) const
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;
		
		return pt;
	}
	const Point& operator-(const Point& arg)
	{
		return Point(this->x - arg.x, this->y - arg.y);
	}
	const Point& operator++()  //전위 증가 연산자
	{
		++x;
		++y;
		return *this;
	}

	const Point& operator++(int) //후위 증가 연산자
	{
		Point pt = *this;
		++* this;
		return pt;
	}
	const Point& operator--()  //전위 감소 연산자
	{
		--x;
		--y;
		return *this;
	}
	const Point& operator--(int) //후위 감소 연산자
	{
		Point pt = *this;
		--* this;
		return pt;
	}
	bool operator==(const Point& arg) const {
		return this->x == arg.x && this->y == arg.y ? true : false;
	}
	bool operator!=(const Point& arg) const {
		return !(*this == arg);
	}
};

const Point& operator-(const Point& argL, const Point& argR)
{
	return Point(argL.x - argR.x, argL.y - argR.y);
}

int main()
{
	Point p1(4, 1), p2(5, 3);
	Point p3, p4;
	Point p5(4, 1);
	//p1.Print();
	//p3.Print();
	//p3 = p1 + p2; //p1.operator+(p2); 와 같음
	//p3.Print();
	//p3 = p1.operator+(p2);// 직접 호출함!
	//p3.Print();
	
	//p3 = --p1;
	//p4 = p2--;

	//p1.Print();
	//p2.Print();
	//p3.Print(); 
	//p4.Print();//p4에는 p2가 후위 증가하기 때문에 (4,2)이 들어감
	if (p1 == p5)
		cout << "p1 == p5" << endl;
	if (p1 != p3)
		cout << "p1 != p3" << endl;

	return 0;
}