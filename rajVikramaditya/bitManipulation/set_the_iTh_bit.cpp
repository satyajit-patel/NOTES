#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 11; //1011
    int i = 2;
    int newNumber1 = (n | (1 << i));
    cout<<newNumber1<<"\n";

    bitset<4> b(11);
    b[i] = 1;
    int newNumber2 = b.to_ullong();
    cout<<newNumber2<<"\n";
    return 0;
}