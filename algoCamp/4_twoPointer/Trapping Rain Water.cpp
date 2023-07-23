// https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        std::vector<int> maxLeg(n, 0), maxOff(n, 0);
        int maxiLeg = INT_MIN, maxiOff = INT_MIN;
        for(int i=0,j=n-1; i<n,j>=0; i++,j--) {
            maxiLeg = std::max(maxiLeg, height[i]);
            maxiOff = std::max(maxiOff, height[j]);
            maxLeg[i] = std::max(maxLeg[i], maxiLeg);
            maxOff[j] = std::max(maxOff[j], maxiOff);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int waterHeight = std::min(maxLeg[i], maxOff[i]);
            int stairHeight = height[i];
            ans += waterHeight - stairHeight;
        }
        return ans;
    }
};