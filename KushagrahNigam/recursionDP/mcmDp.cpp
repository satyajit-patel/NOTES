#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));
int go(vector<int> &arr, int i, int j)
{
    //baseCase
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }


    //recursiveCase
    int ans = INT_MAX;
    for(int k=i; k<j; k++){     //i<=k<j
        int l = go(arr, i, k);
        int r = go(arr, k+1, j);
        int cost = (arr[i-1] * arr[j] * arr[k]);

        ans = min(ans, (l + r + cost));
        dp[i][j] = ans;
    }
    return dp[i][j];
}
int main()
{
    vector<int> arr = {1,2,1,4,1}; //7
    int n = arr.size();
    cout<<go(arr, 1, n-1);
}