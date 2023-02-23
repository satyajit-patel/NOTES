#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
// #define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- 

bool predicate2(int i, int* arr, int target) {
    return arr[i] < target; 
}

bool predicate1(int i, int* arr, int target) {
    return arr[i] <= target; 
}

void input() {
    int n = 10;
    int arr[n] = {1, 1, 1, 2, 2, 2, 3, 5, 6, 7};
    int target = 2;
    // this method only works for integers value, not for float value
    // L is last true
    // R is first false
    // i.e L is MIN-1, R is MAX+1 in search space
    int L = -1; // L is exclusive 
    int R = n; // R is exclusive 
    while(R-L > 1) {
        int M = L + (R-L)/2;
        // (predicate1(M, arr, target)) ? (L = M) : (R = M);
        (predicate2(M, arr, target)) ? (L = M) : (R = M);
    }
    // cout<<"last occurance of target is "<<L<<endl;
    if(L != -1 && arr[L] == target) cout<<"first occurance of target is "<<R<<endl;
    else cout<<-1<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}