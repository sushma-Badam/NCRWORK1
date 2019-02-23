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
	int rear, front;
	int size;
public:
	queue(int t) {
		size = t;
		rear = -1;
		front = -1;
		arr = new T[size];
	}
	void insert(T x) {
		if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
			cout << "Queue Overflow \n";
			return;
		}
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else {
			if (rear == size - 1)
				rear = 0;
			else
				rear = rear + 1;
		}
		cout << "ëlement inserted is: " << x << endl;
		arr[rear] = x;
	}
	T deletel() {
		if (front == -1) {
			cout << "Queue Underflow\n";
		}
		cout << "Element deleted from queue is : " << arr[front] << endl;

		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			if (front == size - 1)
				front = 0;
			else
				front = front + 1;
		}
		return arr[front];
	}
	
};
int main() {
	queue<char>s(4);
	s.insert('A');
	s.insert('B');
	s.insert('C');
	s.insert('D');
	char k = s.deletel();
	s.insert('E');
	k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	k = s.deletel();
	queue<complex>c(5);
	complex c1(1, 2), c2(2, 3), c3(4, 5), c4(6, 7), c5, c6, c7;
	c.insert(c1);
	c.insert(c2);
	c.insert(c3);
	c.insert(c4);
	c.insert(c5);
	c6 = c.deletel();
	getchar();
	return 0;
}