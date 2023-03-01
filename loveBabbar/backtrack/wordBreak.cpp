// https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
    bool f(int i, string& s, unordered_set<string>& set, vector<int>& dp) {
        //baseCase
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        
        string substr = "";
        for(int idx = i; idx<s.size(); idx++) {
            substr += s[idx];
            if(set.find(substr) != set.end()) {
                if(f(idx+1, s, set, dp) == true) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto &it : wordDict) set.insert(it);
        vector<int> dp(s.size()+1, -1);
        return f(0, s, set, dp);
    }
};