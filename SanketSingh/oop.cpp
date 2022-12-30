#include<bits/stdc++.h>

using namespace std;
class Product
{
    string name;
    int price;

    public:
        Product(){} //default constructor
        Product(string n, int p) : name(n), price(p){} //constructor

        void display()
        {
            cout<<"name: "<<name<<"\n"<<"price: "<<price<<"\n\n";
        }

};
int main()
{
    Product p1("IPhone", 100000); //created in stack memory
    Product *p2= new Product("Nokia", 4000); //created in heap memory

    p1.display();
    p2->display();

    return 0;
}