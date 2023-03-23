// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
    public:
    long long trappingWater(int arr[], int n) {
        int maxL[n] = {0};
        int maxR[n] = {0};
        int maxiLeg = INT_MIN;
        int maxiOff = INT_MIN;
        for(int i=0,j=n-1; i<n,j>=0; i++,j--) {
            maxiLeg = std::max(maxiLeg, arr[i]);
            maxiOff = std::max(maxiOff, arr[j]);
            maxL[i] = std::max(maxL[i], maxiLeg);
            maxR[j] = std::max(maxR[j], maxiOff);
        }
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int waterHeight = std::min(maxL[i], maxR[i]);
            int stairHeight = arr[i];
            ans += waterHeight - stairHeight;
        }
        return ans;
    }
};