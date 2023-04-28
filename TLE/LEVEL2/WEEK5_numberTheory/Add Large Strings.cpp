// https://leetcode.com/problems/add-strings/description/
class Solution {
public:
    void largeSum(vector<int>& x, vector<int>& y, vector<int>& ans) {
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        int size = std::min(x.size(), y.size());
        int carry = 0;
        for(int i=0; i<size; i++) {
            int value = x[i] + y[i] + carry;
            int digit = value % 10;
            carry = value / 10;
            ans.push_back(digit);
        }
        if(x.size() > size) {
            for(int i=size; i<x.size(); i++) {
                int value = x[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        if(y.size() > size) {
            for(int i=size; i<y.size(); i++) {
                int value = y[i] + carry;
                int digit = value % 10;
                carry = value / 10;
                ans.push_back(digit);
            }
        }
        while(carry) {
            int digit = carry % 10;
            carry /= 10;
            ans.push_back(digit);
        }
        std::reverse(ans.begin(), ans.end());
    }

    string addStrings(string num1, string num2) {
        std::vector<int> x, y, ans;
        for(auto &it : num1) x.push_back(it - '0');
        for(auto &it : num2) y.push_back(it - '0');
        largeSum(x, y, ans);
        std::string res = "";
        for(auto &it : ans) res += it + '0';
        return res;
    }
};