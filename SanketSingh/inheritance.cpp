//when some class is able to extent the features of alrady made class(only public part) 
//then it is called as inheritance
#include<bits/stdc++.h>

using namespace std;
class Counter
{
    int num;

    public:
        Counter(){}
        Counter(int n) : num(n){} //constructor(setter)

        void display()
        {
            cout<<"yeah..it is public\n\n ";
        }
};

class Product : public Counter //inheritance(now we can inherit/access from Counter class)
{

};
int main()
{
    Counter *c1= new Counter();
    Product p1;
    
    c1->display();
    p1.display();
}