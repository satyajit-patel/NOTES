// https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
class Solution {
public:
    int euclidianGcd(int maxi, int mini) {
        return (mini) ? euclidianGcd(mini, maxi % mini) : maxi;
    }
    int findGCD(vector<int>& nums) {
        int maxi = *std::max_element(nums.begin(), nums.end());
        int mini = *std::min_element(nums.begin(), nums.end());
        // return std::gcd(maxi, mini);
        return euclidianGcd(maxi, mini);
    }
};