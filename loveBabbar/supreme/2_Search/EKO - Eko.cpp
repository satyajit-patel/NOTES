#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://www.spoj.com/problems/EKO/

bool predicate(int mid, int* arr, int n, int requireWood) {
    int curWood = 0;
    for(int i=0; i<n; i++) if(mid <= arr[i]) curWood += arr[i] - mid;
    return curWood >= requireWood;
}

void input() {
    int n,m; cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int L = -1, H = 1e9+1;
    while(H-L > 1) {
        int mid = L + (H-L)/2;
        (predicate(mid, arr, n, m)) ? (L = mid) : (H = mid);
    } 
    cout<<L<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}