#include<iostream>
using namespace std;
class shape {
	int dimension1;
public:
	virtual float area() {
		return dimension1*dimension1;
	}
};
class Triangle :public shape {
	int base;
	int height;
public:
	Triangle(int a, int b) {
		base = a;
		height = b;
	}
	float area() {
		cout << "area of a triangle is:" << (0.5*base*height) << endl;
		return (0.5*base*height);
	}
};
class Rectangle :public shape {
	int breadth;
	int height;
public:
	Rectangle(int a, int b) {
		breadth = a;
		height = b;
	}
	float area() {
		cout << "area od rectangle is:" << breadth*height << endl;
		return (breadth*height);
	}
};
class square :public shape {
	int side;
public:
	square(int a) {
		side = a;
	}
	float area() {
		cout << "area of square is:" << (side*side) << endl;
		return side*side;
	}
};
int main() {
	shape *k;
	Triangle T(2,3);
	Rectangle R(3,4);
	square s(4);
	k = &T;
	k->area();
	k = &R;
	k->area();
	k = &s;
	k->area();
	getchar();
	return 0;
}