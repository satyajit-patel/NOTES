#include<iostream>

using namespace std;
class emp {
public:
    int a, b;
    void show() {
        int x=10, y=20;
        cout<<x<<" "<<y<<endl;
    }
    void display() {
        cout<<this->a<<" "<<this->b<<endl;
    }
};
int main() {
    static emp obj; //this take out the garbage values and assign 0 to all data members outside the method
    obj.display();
    obj.show();
    return 0;
}