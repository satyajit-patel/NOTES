// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
private:
    int numOfColors;
    int const MOD = 1e9+7;
    std::vector<long long> dp;
    long long f(int fence) {
        // base case
        if(fence == 1) return numOfColors;
        if(fence == 2) return numOfColors * numOfColors;
        if(dp[fence] != -1) return dp[fence];
        
        // recursive case
        long long sameColCombinations = f(fence-2)*(numOfColors-1);
        long long diffColCombinations = f(fence-1)*(numOfColors-1);
        
        // work case
        long long ans = (sameColCombinations+diffColCombinations)%MOD;
        
        // return case
        dp[fence] = ans;
        return ans;
    }
public:
    long long countWays(int n, int k) {
        numOfColors = k;
        dp.resize(n+1, -1);
        return f(n);
    }
};