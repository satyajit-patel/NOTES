#include<bits/stdc++.h>
using namespace std;

//A xor 0 = A
//A xor 1 = ~A
//A xor A = 0;
int main() {
    int a = 12, b = 13;

    a = (a ^ b); //a = (12 ^ 13); 
    b = (a ^ b); //b = ((12 ^ 13) ^ 13) == (12 ^ 0) == 12;
    a = (a ^ b); //a = ((12 ^ 13) ^ 12) == (0 ^ 13) == 13;

    cout<<a<<" "<<b;
    return 0;
}