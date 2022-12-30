//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/submissions/
class Solution {
public:
    bool blackBox(int mid, vector<int> &nums, int threshold) {
        int sum = 0;
        for(auto &it : nums) {
            sum += (it/mid);
            if(it%mid != 0) sum += 1; //because we have to take the shield value
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), ans = high;
        while(low <= high) {
            int mid = (low + high)/2;
            if(blackBox(mid, nums, threshold)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};