/*
public----> 
	we can access the public members of base class even through the
	object of child class
private---->
	we can't acces the private members of base class directly
	but through the getter function of base class
protected-->
	we can't acces the protected members of base class directly
	but we can access
	by directly initializing to any variable of child class and
	through getter function of base class
*/

//ist base class Constructor gets Called
//ist child class Destructor gets destroy
#include <bits/stdc++.h>

using namespace std;
class A {
protected:
	int item;
private:
	int val;
public:
	string name;

	//defaultConstructor
	A() {
		cout<<"base class Constructor Called\n";
		this->item = 10;
		this->val = 20;
		this-> name = "Sanket Singh";
	}

	//Destructor
	~A() {
		cout<<"base class Destructor Called\n";
	}

	//copyConstructor
	A(const A &obj) {
		cout<<"base class copyConstructor Called\n";
	}

	//getter function
	int getVal() {
		return val;
	}
	int getItem() {
		return item;
	}
	void display() {
		cout<<this->item<<" "<<this->val<<" "<<this->name<<"\n";
	}

	friend class fuck;
	/*i.e we are saying to class A that class fuck is your friend
	he can fuck you.....but not vice versa
	i.e we can access the members of class A from fuck class not directly
	but through the function of fuck class
	*/
};

//inheritance
class B : public A {
public:
	int x = item;
	B() {
		cout<<"child class Constructor Called\n";
	}
	~B() {
		cout<<"child class Destructor Called\n";
	}
	B(const B &obj) {
		cout<<"child class copyConstructor Called\n";
	}
};

//friend class
class fuck {
public:
	string getPublicValue(A &a1) {
		return a1.name;
	}
	int getProtectedValue(A &a1) {
		return a1.item;
	}
	int getPrivateValue(A &a1) {
		return a1.val;
	}

    fuck() {
		cout<<"friend class Constructor Called\n";
	}
	~fuck() {
		cout<<"friend class Destructor Called\n";
	}
};
int main() {
    A *a0 = new A;
    delete a0;
    cout<<"-----------------------------\n";
	A a1;//this object will call only base class Constructor
    cout<<"-----------------------------\n";
	fuck f1;
	cout<<"-----------------------------\n";
	B *b1 = new B;//this object will call the both class Constructor
	cout<<"-----------------------------\n";
	B b5;
	cout<<"-----------------------------\n";
	A b2 = a1;
	cout<<"-----------------------------\n";
	//B b6 = b1; this will give Error as one is in Stack and b1 is in Heap
	B b6 = b5;
	cout<<"-----------------------------\n";
	a1.display();
	b1->display();

	//a1 and b2 are allocate memory on Stack(space deallocated auto)
	//b1 will allocate memory on Heap(we have to deallocate the space manually
	//otherwise Destructor will not get Called)
	
	//here--> ist Destructor of a0(Heap and baseClass) will trigger ist then b6(Stack and childClass), 
    //b2(Stack and baseClass), b5(Stack and childClass), b1(Heap and childClass...will not execute at all as we not deleted), 
    //f1(stack, friendClass), a1(Stack and baseClass);
	cout<<"-----------------------------\n";

	//access
	cout<<a1.name<<"\n";
	cout<<b1->name<<"\n";
	cout<<b1->getVal()<<"\n";
	cout<<b5.getVal()<<"\n";
	cout<<b1->x<<"\n";
	cout<<b6.getItem()<<"\n";
	cout<<f1.getPublicValue(a1)<<" ";
	cout<<f1.getProtectedValue(a1)<<" "<<f1.getPrivateValue(a1)<<"\n";
	return 0;
}