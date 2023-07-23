class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int istId = lower_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
            int lastId = (upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin())-1;
            int numOfOccurance = lastId-istId+1;
            if(numOfOccurance == 1) return nums[i];
        }
        return -1;
    }
};