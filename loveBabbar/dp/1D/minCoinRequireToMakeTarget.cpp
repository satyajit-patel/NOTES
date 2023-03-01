#include<bits/stdc++.h>
using namespace std;

int f(int target, vector<int>& arr, vector<int>& dp) {
    //baseCase
    if(target == 0) return 0;
    if(target < 0) return 1e8;
    if(dp[target] != -1) return dp[target];
    
    int ans = 1e8;
    for(int i=0; i<arr.size(); i++) {
        int coin = 1 + f(target-arr[i], arr, dp);
        ans = min(ans, coin);
    }
    dp[target] = ans;
    return ans;
}
int main() {
    int target = 7;
    vector<int> arr = {1,2,3};
    vector<int> dp(target+1, -1);
    int ans = f(target, arr, dp);
    if(ans < 1e8) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}