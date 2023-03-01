// https://leetcode.com/problems/next-greater-element-ii/description/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.end(), nums.begin(), nums.end());

        std::stack<int> stack;
        std::vector<int> nge(n);
        for(int i=nums.size()-1; i>=0; i--) {
            while(!stack.empty() && stack.top() <= nums[i]) stack.pop();
            if(stack.empty()) nge[i % n] = -1;
            else nge[i % n] = stack.top();
            stack.push(nums[i]);
        }

        return nge;
    }
};