#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

//tc,sc->O(N)
int fact(int n) {
    if(n <= 1) return 1;//i know this much
    return n * fact(n-1);
}
int main() {
    int n; cin>>n;
    cout<<fact(n);
    return 0;
}