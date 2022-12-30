#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 11; //1011
    int i = 2;
    if( (n & (1 << i)) != 0) cout<<"set\n";
    else cout<<"not set\n";

    bitset<16> b(11);
    if(b[2] == 1) cout<<"set\n";
    else cout<<"not set\n";
    return 0;
}