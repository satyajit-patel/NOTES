#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

//tc->O(2^N), sc->O(N)
int fibo(int n) {
    if(n <= 1) return n;//i know this much
    int prev = fibo(n-1);
    int prevPrev = fibo(n-2);
    return prev + prevPrev;
}
int main() {
    int n; cin>>n;
    cout<<fibo(n);
    return 0;
}