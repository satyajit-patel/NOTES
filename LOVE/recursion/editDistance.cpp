//https://leetcode.com/problems/edit-distance/submissions/
class Solution {
public:
    int f(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        //baseCase
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        
        //recursiveCase
        if(a[i] == b[j]) return 0 + f(i+1, j+1, a, b, dp);
        else {
            int ins = 1 + f(i, j+1, a, b, dp);
            int rep = 1 + f(i+1, j+1, a, b, dp);
            int del = 1 + f(i+1, j, a, b, dp);
            return dp[i][j] = min(ins, min(rep, del));
        }
    }
    int minDistance(string word1, string word2) {
        //changing parametre = 2 so 2D dp
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return f(0, 0, word1, word2, dp);
    }
};