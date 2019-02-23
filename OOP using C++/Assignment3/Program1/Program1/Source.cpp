#include<iostream>
using namespace std;
class complex {
	float real;
	float img;
public:
	complex() {
		real = 0;
		img = 0;
	}
	complex(float a, float b) {
		real = a;
		img = b;
	}
	void add(float i) {
		(*this).real = i;
		(*this).img = i;
	}
	bool operator== (complex b) {
		return((real == b.real) && (img == b.img));
	}
};
template <class T, class T1 = int>
int Lsearch(T *a, T ele, T1 n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == ele) {
			return i;
		}
	}
	return 0;
}
template<>
int Lsearch(char *a, char ele, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == ele) {
			return i;
		}
	}
	return 0;
}
int main() {
	int arrInt[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int ele = 5;
	int k = Lsearch(arrInt, ele, 10);
	cout << "int:" << k;
	float arrFloat[5] = { 1.1,2.2,3.3,4.4,5.5 };
	float elem = 3.3;
	int j = Lsearch(arrFloat, elem, 5.00f);
	cout << "float:" << j;
	char a[8] = { 'n','c','r','c','d','a','c' };
	char eleme = 'c';
	int l = Lsearch<char>(a, eleme, 8);
	cout << "explicit specialization:" << l;
	complex c[5];
	float g = 1;
	for (int i = 0; i < 5; i++) {
		c[i].add(g);
		g++;
	}
	complex element(3, 3);
	int b = Lsearch(c, element, 5);
	cout << "Complextype:" << b;
	getchar();
	return 0;
}