#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 11; //1011
    int i = 1;
    int newNumber = (n & ~(1 << i));
    cout<<newNumber<<"\n";

    bitset<4> b(n);
    b[1] = 0;
    int newNumber2 = b.to_ullong();
    cout<<newNumber2<<"\n";
    return 0;
}