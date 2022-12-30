#include<bits/stdc++.h>
using namespace std;

int f(int length, int size1, int size2, int size3, vector<int>& dp) {
    //baseCase
    if(length == 0) return 0;
    if(length < 0) return INT_MIN;
    if(dp[length] != -1) return dp[length];
    
    int cut1 = 1 + f(length-size1, size1, size2, size3, dp);
    int cut2 = 1 + f(length-size2, size1, size2, size3, dp);
    int cut3 = 1 + f(length-size3, size1, size2, size3, dp);
    
    int ans = max(cut1, max(cut2, cut3));
    dp[length] = ans;
    return ans;
}
int main() {
    int length = 17;
    vector<int> dp(length+1, -1);
    int ans = f(length, 10, 11, 3, dp);
    if(ans < 0)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}