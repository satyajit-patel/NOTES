// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
class Solution {
public:
    bool isVowel(char ch) {
        ch = std::tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    string reverseVowels(string& s) {
        int low = 0, high = s.size()-1;
        while(low < high) {
            if(isVowel(s[low]) && isVowel(s[high])) std::swap(s[low++], s[high--]);
            if(!isVowel(s[low])) low++;
            if(!isVowel(s[high])) high--;
        }
        return s;
    }
};