#include<iostream>

using namespace std;
class Base {
public:
	virtual void print() = 0;
};
class Derived : public Base {
public:
	void print() {
		cout<<"Derived class\n";
	}
};
int main() {
	Derived d1;
	d1.print();
	Base *b1 = &d1;
	b1->print();
	return 0;
}