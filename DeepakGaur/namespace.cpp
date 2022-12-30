#include<iostream>

using namespace std;
namespace first {
    int display() {
        return 100;
    }
}
namespace satyajit {
    string show() {
        return "satyajit patel";
    }
}
using namespace satyajit;
int main() {
    cout<<first::display();
    cout<<show();
    return 0;
}