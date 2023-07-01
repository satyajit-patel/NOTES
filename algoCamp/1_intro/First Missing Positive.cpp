// https://leetcode.com/problems/first-missing-positive/description/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        bool isContainsOne = false;
        for(auto &it : nums) {
            if(it == 1) {
                isContainsOne = true;
                break;
            }
        }
        if(!isContainsOne) return 1;

        for(int i=0; i<N; i++) if(nums[i]<=0 || nums[i]>N) nums[i] = 1;
        for(int i=0; i<N; i++) {
           int index = std::abs(nums[i]);
           if(index == N) nums[0] = -std::abs(nums[0]);
           else nums[index] = -std::abs(nums[index]);
        }
        for(int i=1; i<N; i++) if(nums[i] > 0) return i;
        if(nums[0] > 0) return N;
        return N+1;
    }

};