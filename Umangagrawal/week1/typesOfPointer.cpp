#include<bits/stdc++.h>

using namespace std;
class employee {
private:
    int salary;
    int empId;
public:
    string name;
    string address;

    //constructor-----> its called when object is created
    //parameterisedConstructor
    employee(string name) {
        cout<<"Constructor Called\n";
        this->name = name;
        this->salary = 500;
        this->empId = 1;
        this->address = "Delhi";
    }
    //defaultConstructor
    employee() {
        cout<<"Constructor Called\n";
        this->name = "None";
        this->salary = 500;
        this->empId = 1;
        this->address = "Delhi";
    }

    //desstructor-----> its called when the class is about to destroy
    //number of Destructor Called == number of object present
    ~employee() {
        cout<<"Destuctor Called\n";
        cout<<"Thanl You\n";
    }

    //copyConstructor---> its called only when we create a new object from existing object
    //syntax-----> className(const className objectsReference) {}
    employee(const employee &e) {
        cout<<"copyConstructor Called\n";
    }
    void display() {
        cout<<this->name<<"\n"<<this->address<<"\n"<<this->salary<<"\n"<<this->empId<<"\n";
    }

    //setter and getter funtions(used to access the Private members)
    //setterFunction
    void setSalary(int salary) {
        //businessLogic
        if(salary < 1) return;

        this->salary = salary;
        return;
    }

    //getterFunction
    int getSalary() {
        return salary;
    }
};
int main() {
    //nullPointer(points to starting address)
    int *ptr1 = 0;
    int *ptr2 = NULL;

    //wildPointer(points to nothing)
    int *ptr3;

    //danglingPointer(points to unauthorized address)
    int *ptr4 = new int; //space will allocated in Heap
    *ptr4 = 4;
    cout<<*ptr4<<"\n";

    cout<<ptr4<<"\n";
    delete ptr4;
    cout<<*ptr4<<"\n";//----------> this will give Garbage value.. as the value's space was deleted from heap

    cout<<ptr4<<"\n";//this will print the same address but this is unauthorized....
                    //as its space was manually deleted from Heap but the address is still present in Stack
                    //so we can call this pointer as Dangling pointer

    ptr4 = NULL; //now this is no more a dangling pointer(its now null pointer)

    cout<<"---------------------\n";

    employee e1("Sanket Singh");
    e1.display();
    e1.setSalary(500000);
    cout<<e1.getSalary()<<"\n";
    cout<<"----------------------\n";
    employee e2 = e1;//------------>will trigger the copyConstructor
    cout<<"----------------------\n";
    employee e3;
    e3 = e1;//------------>will not trigger the copyConstuctor as the object is already created
    cout<<"----------------------\n";
    return 0;
}