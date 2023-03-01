#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1085

bool predicate(int M, int* arr, int n, int k) {
    int cut = 1; // because even if we don't cut any, bydefault it is 1 cut (1 piece)
    int sum = 0;
    bool ok = true;
    for(int i=0; i<n; i++) {
        // edge case
        if(arr[i] > M) {
            ok = false;
            break;
        }
        sum += arr[i];
        if(sum > M) {
            cut++;
            sum = arr[i];
        }
    }
    return ok && cut <= k;
}

void input() {
    int n,k; cin>>n>>k;
    int arr[n];
    for(auto &it : arr) cin>>it;
    int sum = 0;
    for(auto &it : arr) sum += it;
    
    int L = -1, H = sum+1;
    while(H-L > 1) {
        int M = L + (H-L)/2;
        // as here we have to minimize the maximum, so we shrink the "H" if predicate is valid
        (predicate(M, arr, n, k)) ? (H = M) : (L = M);
    }
    cout<<H<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}