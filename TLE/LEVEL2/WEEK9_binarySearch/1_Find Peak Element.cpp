// https://leetcode.com/problems/find-peak-element/description/
class Solution {
public:
    bool predicate(int i, vector<int>& nums) {
       return (i == 0) || (nums[i-1] < nums[i]);
    }
    int findPeakElement(vector<int>& nums) {
        int L = -1; // min-1 // first value of L is excluded
	int H = nums.size(); // max+1 // excluded
        while(H-L > 1) {
            int M = L + (H - L)/2;
            (predicate(M, nums)) ? L = M : H = M;
        }
        return L;
    }
};