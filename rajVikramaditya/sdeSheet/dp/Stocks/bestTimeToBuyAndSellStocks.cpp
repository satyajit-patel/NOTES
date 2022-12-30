//https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int buyMini = prices[0];
    int maxProfit = 0;
    for(int i=0; i<n; i++) {
        int sellProfit = prices[i] - buyMini;
        maxProfit = max(maxProfit, sellProfit);
        buyMini = min(buyMini, prices[i]);
    }
    return maxProfit;
}