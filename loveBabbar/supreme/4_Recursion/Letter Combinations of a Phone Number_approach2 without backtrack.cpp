// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
public:
    void f(vector<string>& ans, string output, string& digits, int n, vector<string>& mpp, int i=0) {
        // base case
        if(i >= n) {
            ans.push_back(output);
            return;
        }

        // recursive case
        int digit = digits[i] - '0'; // convert char --> int
        string temp = mpp[digit];
        for(int ch=0; ch<temp.size(); ch++) f(ans, output + temp[ch], digits, n, mpp, i+1);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(digits.size() == 0) return ans;
        string output = "";
        vector<string> mpp(10);
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        f(ans, output, digits, n, mpp);
        return ans;
    }
};