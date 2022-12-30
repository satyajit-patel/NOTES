#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000, 0));
int knapsak(int val[], int wt[], int w, int n)
{
    //baseCase
    if(w == 0 || n == 0) return 0;
    if(dp[n][w] != 0) return dp[n][w];



    //recursiveCase
    if(wt[n-1] <= w){
        //takeIt
        int x = val[n-1] + knapsak(val, wt, w-wt[n-1], n-1);

        //!takeIt
        int y = knapsak(val, wt, w, n-1);

        return dp[n][w] = max(x, y);
    }
    else{
        //discard
        return dp[n][w] = knapsak(val, wt, w, n-1);
    }
}
int main()
{
    int n=3;
    int w=50;
    int val[n] = {60, 100, 120};
    int wt[n] = {10, 20, 30};

    cout<<knapsak(val, wt, w, n);
    return 0;
}