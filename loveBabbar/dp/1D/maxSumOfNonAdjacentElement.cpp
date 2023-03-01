#include<bits/stdc++.h>
using namespace std;

int recTime = 0;
int memoTime = 0;
int f2(int i, vector<int>& arr, vector<int>& dp) {
    memoTime += 1;
    //baseCase
    if(i >= arr.size()) return 0;
    if(dp[i] != -1) return dp[i];
    
    //include
    int incl = arr[i] + f2(i+2, arr, dp);
    
    //exclude
    int excl = 0 + f2(i+1, arr, dp);
    
    int ans = max(incl, excl);
    dp[i] = ans;
    return ans;
}
int f1(int i, vector<int>& arr) {
    recTime += 1;
    //baseCase
    if(i >= arr.size()) return 0;
    
    //include
    int incl = arr[i] + f1(i+2, arr);
    
    //exclude
    int excl = 0 + f1(i+1, arr);
    
    return max(incl, excl);
}
int main() {
    vector<int> arr = {2,1,4,9};
    cout<<f1(0, arr)<<" with recursion time "<<recTime<<endl;
    vector<int> dp(arr.size()+1, -1);
    cout<<f2(0, arr, dp)<<" with memoization time "<<memoTime<<endl;
    return 0;
}