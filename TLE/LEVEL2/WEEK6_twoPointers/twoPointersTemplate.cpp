#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- min sum subarray >= k for only +ve elements

void input() {
    int n,k; cin>>n>>k;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    /*
        in strictly incresing binary search, we can use two pionters either
        bellow is basic template for 2 pointers

        for (int l = 0, r = -1; l < n; l++) {
            while (condition to increase r)
                // increase r

            if (valid)
                // update value
        }
    */
    int sum = 0, mini = 1e9;
    for (int l=0,r=-1; l<n; l++) {
        while (sum<k && r+1<n)
            sum += arr[++r];
        if(sum >= k)
            mini = min(mini, r-l+1);
        sum -= arr[l];
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}