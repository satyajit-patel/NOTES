#include<bits/stdc++.h>

using namespace std;
void f(int *number)
{
    int value=5;
    number=&value;// now number will point value

    *number= *number + 10;
    cout<<"value="<<value<<"\n";
}
int main()
{
    int num=20;
    f(&num);//passing its address as a value
    cout<<"num="<<num<<"\n";
    return 0;
}