// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // binary search on index
        int N = nums.size();
        // observation :-
        // before ans ist element is on even index and 2nd ele is on odd index
        // after ans ist element is on odd index and 2nd ele is on even index
        
        // edge case : just take H-L >= 1 (as we need ans itself)
        int L = 0, H = N-1;
        while(L <= H) {
            if(L == H) return nums[L];
            int M = L + (H-L)/2;
            if(M%2 == 0) {
                if(nums[M] == nums[M+1]) L = M+2; // ie we're on left side of ans, so go right 
                else H = M;
            }
            else {
                if(nums[M] == nums[M-1]) L = M+1; // ie again we are on left side
                else H = M;
            }
        }
        return -1;
    }
};