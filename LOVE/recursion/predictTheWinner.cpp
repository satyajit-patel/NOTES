//https://leetcode.com/problems/predict-the-winner/
class Solution {
public:
    int f(int i, int j, vector<int> &nums) {
        //baseCase
        if(i > j) return 0;
        if(i == j) return nums[i];
        
        //recursiveCase
        int choice1 = nums[i] + min(f(i+2, j, nums), f(i+1, j-1, nums));
        int choice2 = nums[j] + min(f(i+1, j-1, nums), f(i, j-2, nums));
        return max(choice1, choice2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int totalScore = 0;
        for(auto &it : nums) totalScore += it;
        int player1Score = f(0, nums.size()-1, nums);
        int player2Score = totalScore - player1Score;
        return player1Score >= player2Score;
    }
};