// https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/
class Solution {
public:
    long long maxArrayValue(vector<int>& _nums) {
        vector<long long> nums;
        for(auto& it:_nums) nums.push_back(it);
        // just greedy 
        // foving from right to left and making the right sum as big as possible
        auto it = nums.end()-1;
        while(it != nums.begin()) {
            if((*it) >= (*(it-1))) {
                *it = (*it) + (*(it-1));
                nums.erase(it-1);
            }
            it--;
        }
        return *std::max_element(nums.begin(), nums.end());
    }
};