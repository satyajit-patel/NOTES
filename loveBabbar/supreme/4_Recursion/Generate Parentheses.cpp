// https://leetcode.com/problems/generate-parentheses/description/
class Solution {
public:
    void f(vector<string>& ans, string& output, int openBracket, int closeBracket) {
        // base case
        if(openBracket==0 && closeBracket==0) {
            ans.push_back(output);
            return;
        }

        // include open bracket
        if(openBracket > 0) {
            output.push_back('(');
            f(ans, output, openBracket - 1, closeBracket);
            output.pop_back(); // backtrack
        }

        // include close bracket
        if(closeBracket > openBracket) {
            output.push_back(')');
            f(ans, output, openBracket, closeBracket - 1);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        f(ans, output, n, n);
        return ans;
    }
};