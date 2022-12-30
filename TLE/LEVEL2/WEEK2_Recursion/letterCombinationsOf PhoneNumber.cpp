// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
public:
    void f(int i, string s, string digits, unordered_map<int, string>& m, vector<string>& ans) {
        // base case
        if(i == digits.size()) {
            ans.push_back(s);
            return;
        }

        // convert char --> int
        int num = digits[i] - '0';
        string temp = m[num];
        for(int x=0; x<temp.size(); x++) {
            s.push_back(temp[x]);
            f(i+1, s, digits, m, ans);
            // backtrack
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        f(0, "", digits, m, ans);
        return ans;
    }
};