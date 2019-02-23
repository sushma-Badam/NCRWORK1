#include<iostream>
using namespace std;
class complex {
	float real;
	float img;
public:
	complex(float a, float b) {
		real = a;
		img = b;
	}
	complex() {
		real = 0;
		img = 0;
	}
	friend ostream & operator<<(ostream &out, complex &c);
};
ostream & operator<<(ostream &out, complex &c)
{
	out <<c.real << "+i" << c.img <<endl;
	return out;
}
template<class T>
class stack {
	T *arr;
	int top;
	int size;
public:
	stack(int t) {
		size = t;
		top = 0;
		arr = new T[size];
	}
	void push(T x) {
		if (top == size) {
			throw "stack is full!";
		}
		else {
			cout << "inserting  " << x << endl;
			arr[top++] = x;
		}
	}
	T pop() {
		if (top == 0) {
			throw "stack is empty!";
		}
		else {
			T k = arr[top];
			cout <<"deleting  "<< arr[top-1] << endl;
			top--;
			return k;
		}
	}
	T peek() {
		if (top == 0) {
			cout << "no elements" << endl;
		}
		else {
			cout << "peek element is  " << arr[top - 1] << endl;
			return arr[top-1];
		}
	}
};
int main() {
	stack<char>s(10);
	try {
		s.push('A');
		s.push('B');
		s.push('C');
		s.push('D');
		s.push('E');
		char k = s.pop();
		char j = s.peek();
		stack<complex>c(5);
		complex c1(1, 2), c2(2, 3), c3(4, 5), c4(6, 7), c5, c6, c7;
		c.push(c1);
		c.push(c2);
		c.push(c3);
		c.push(c4);
		c.push(c5);
		c6 = c.pop();
		c7 = c.peek();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	getchar();
	return 0;
}