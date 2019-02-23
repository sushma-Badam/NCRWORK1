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
	out << c.real << "+i" << c.img;
	return out;
}
template<class T>
class queue {
	T *arr;
	int rear,front;
	int size;
public:
	queue(int t) {
		size = t;
		rear = 0;
		front = 0;
		arr = new T[size];
	}
	void insert(T x) {
		if (rear == size) {
			cout << "stack is full" << endl;
		}
		else {
			cout << "inserting  " << x << endl;
			arr[rear++] = x;
		}
	}
	T deletel() {
		if (rear == 0 || rear==front) {
			cout << "stack is empty" << endl;
		}
		else {
			T k = arr[front];
			cout << "deleting  " << arr[front] << endl;
			front++;
			return k;
		}
	}
	T peek() {
		if (rear == 0) {
			cout << "no elements" << endl;
		}
		else {
			cout << "peek element is  " << arr[rear - 1] << endl;
			return arr[rear-1];
		}
	}
};
int main() {
	queue<char>s(10);
	s.insert('A');
	s.insert('B');
	s.insert('C');
	s.insert('D');
	s.insert('E');
	char k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	char j = s.peek();
	queue<complex>c(5);
	complex c1(1, 2), c2(2, 3), c3(4, 5), c4(6, 7), c5, c6, c7;
	c.insert(c1);
	c.insert(c2);
	c.insert(c3);
	c.insert(c4);
	c.insert(c5);
	c6 = c.deletel();
	c7 = c.peek();
	getchar();
	return 0;
}