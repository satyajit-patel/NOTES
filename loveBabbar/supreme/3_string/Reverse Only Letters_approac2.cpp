// https://leetcode.com/problems/reverse-only-letters/description/
class Solution {
public:
    string reverseOnlyLetters(string& s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(std::isalpha(s[i]) && std::isalpha(s[j])) std::swap(s[i++], s[j--]);
            else if(!std::isalpha(s[i])) i++;
            else if(!std::isalpha(s[j])) j--;
        }
        return s;
    }
};