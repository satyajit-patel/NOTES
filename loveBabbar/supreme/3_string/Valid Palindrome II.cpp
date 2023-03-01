// https://leetcode.com/problems/valid-palindrome-ii/description/
class Solution {
public:
    bool f(string& s, int i, int j) {
        // check palindrome 
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string& s) {
        int i=0, j=s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) return f(s, i, j-1) || f(s, i+1, j);
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};