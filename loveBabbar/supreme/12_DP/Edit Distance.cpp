// https://leetcode.com/problems/edit-distance/description/
class Solution {
private:
    string s1, s2;
    vector<vector<int>> dp;

    int f(int i, int j) {
        // base case
        if(i >= s1.size()) return s2.size()-j;
        if(j >= s2.size()) return s1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int mini = INT_MAX;
        if(s1[i] == s2[j]) {
            int ans = f(i+1, j+1);
            mini = std::min(mini, 0+ans);
        }
        else {
            int insertAns = f(i, j+1);
            mini = std::min(mini, 1+insertAns);
            int deleteAns = f(i+1, j);
            mini = std::min(mini, 1+deleteAns);
            int replaceAns = f(i+1, j+1);
            mini = std::min(mini, 1+replaceAns);
        }

        // return case
        dp[i][j] = mini;
        return mini;
    }
public:
    int minDistance(string word1, string word2) {
        s1 = word1, s2 = word2;
        if(!s1.size()) return s2.size();
        if(!s2.size()) return s1.size();
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return f(0, 0);
    }
};