#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 8;
    if( (n & (n-1)) == 0) cout<<"it's a power of 2";
    else cout<<"it's not a power of 2";
    return 0;
}