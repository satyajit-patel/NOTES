#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://leetcode.com/problems/maximum-subarray/description/

int kadanes(vi& arr) {
    int maxi = 0, curSum = 0, startIndex = 0, endIndex = 0;
    for(int i=0; i<arr.size(); i++) {
        curSum += arr[i];

        // not worth it to take
        if(curSum < 0) {
            curSum = 0;
            startIndex = i+1;
        }

        if(curSum > maxi) {
            maxi = curSum;
            endIndex = i;
        }
    }
    // max subarray is
    for(int i=startIndex; i<=endIndex; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return maxi;
}

void input() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    int maxi = *std::max_element(arr.begin(), arr.end());
    if(maxi < 0) cout<<maxi<<endl;
    else cout<<kadanes(arr)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

