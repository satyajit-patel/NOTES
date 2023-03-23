// https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }

    string longestPalindrome(string& s) {
        std::string ans = "";
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(isPalindrome(s, i, j)) {
                    std::string temp = s.substr(i, j-i+1);
                    ans = (temp.size() > ans.size()) ? (temp) : (ans);
                }
            }
        }
        return ans;
    }
};