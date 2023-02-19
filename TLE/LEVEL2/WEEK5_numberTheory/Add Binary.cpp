// https://leetcode.com/problems/add-binary/description/
class Solution {
public:
    string addBig(string& a, string& b, vector<int>& x, vector<int>& y) {
        string ans = "";
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        int mxLen = std::min(x.size(), y.size());
        int carry = 0;
        for(int i=0; i<mxLen; i++) {
            int value = x[i] + y[i] + carry;
            if(value == 1) {
                ans += '1';
                carry = 0;
            }
            else if(value == 2) {
                ans += '0';
                carry = 1;
            }
            else if(value == 3) {
                ans += '1';
                carry = 1;
            }
            else if(value == 0) {
                ans += '0';
                carry = 0;
            }
        }
        if(a.size() > mxLen) {
            for(int i=mxLen; i<x.size(); i++) {
                int value = x[i] + carry;
                if(value == 1) {
                    ans += '1';
                    carry = 0;
                }
                else if(value == 2) {
                    ans += '0';
                    carry = 1;
                }
                else if(value == 3) {
                    ans += '1';
                    carry = 1;
                }
                else if(value == 0) {
                    ans += '0';
                    carry = 0;
                }
            }
        }
        if(b.size() > mxLen) {
            for(int i=mxLen; i<y.size(); i++) {
                int value = y[i] + carry;
                if(value == 1) {
                    ans += '1';
                    carry = 0;
                }
                else if(value == 2) {
                    ans += '0';
                    carry = 1;
                }
                else if(value == 3) {
                    ans += '1';
                    carry = 1;
                }
                else if(value == 0) {
                    ans += '0';
                    carry = 0;
                }
            }
        }
        if(carry != 0) ans += '1';
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    string addBinary(string a, string b) {
        vector<int> x, y;
        for(int i=0; i<a.size(); i++) x.push_back(a[i] - '0');
        for(int i=0; i<b.size(); i++) y.push_back(b[i] - '0');
        return addBig(a, b, x, y);
    }
};