// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void f(string s, int open, int close, vector<string>& ans, int n) {
        // base case
        if(s.size() == 2*n) {
            ans.push_back(s);
            return;
        }

        if(open < n) f(s + "(", open + 1, close, ans, n);
        if(close < open) f(s + ")", open, close + 1, ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f("(", 1, 0, ans, n);
        return ans;
    }
};