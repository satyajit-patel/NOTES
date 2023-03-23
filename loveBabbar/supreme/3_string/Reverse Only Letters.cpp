// https://leetcode.com/problems/reverse-only-letters/description/
class Solution {
public:
    bool notChar(char ch) {
        ch = std::tolower(ch);
        return !(ch >= 'a' && ch <= 'z');
    }

    bool bothValidChar(char ch1, char ch2) {
        ch1 = std::tolower(ch1);
        ch2 = std::tolower(ch2);
        return (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z');
    }

    string reverseOnlyLetters(string s) {
        int N = s.size();
        int i = 0, j = N-1;
        while(i < j) {
            if(bothValidChar(s[i], s[j])) std::swap(s[i++], s[j--]);
            else if(notChar(s[i])) i++;
            else if(notChar(s[j])) j--;
        }
        return s;
    }
};