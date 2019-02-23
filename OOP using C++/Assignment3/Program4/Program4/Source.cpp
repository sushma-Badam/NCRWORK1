#include<iostream>
using namespace std;
class base {
	int b_private;
protected:
	int b_protected;
public:
	int b_public;
};
class derived1 :public base {
public:
	derived1() {
		//b_private= cannot be accessed and used
		b_protected = 3;
		b_public = 4;
		cout << "b_protected:  " << b_protected << "  b_public  " << b_public << endl;
	}
};
class derived2 :protected base {
public:
	derived2() {
		//b_private cannot be accesed
		b_protected = 17;
		b_public = 16;
		cout << "b_protected:  " << b_protected << "  b_public  " << b_public << endl;
	}
};
class derived3 :private base {
public:
	derived3() {
		b_protected = 119;
		b_public = 118;
		cout << "b_protected:  " << b_protected << "  b_public  " << b_public << endl;
	}
};
int main() {
	base b;
	b.b_public = 2;
	cout << "base class variables accessed in main are:" << b.b_public << endl;
	//private and protected variables cant be accessed in main
	derived1 d1;
	d1.b_public = 22;
	cout << "derived public variables accessed are public only" << d1.b_public << endl;
	//private and protected of dervived came from base class remain same unacceseed in main
	derived2 d2;
	//deriving using protected makes all protected and cant be accessed in main
	derived3 d3;
	//deriving using private makes all private and cant be accessed in main
	getchar();
	return 0;
}