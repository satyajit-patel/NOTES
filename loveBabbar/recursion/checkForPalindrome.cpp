//https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?leftPanelTab=1
#include <bits/stdc++.h> 
bool isPalindrome(int i, int j, string& s) {
    //base case
    if(i >= j) return true;
    if(s[i] != s[j]) return false;
    
    
    //recursive case
    return isPalindrome(i+1, j-1, s);
}
bool checkPalindrome(string s) {
    //case sensitive so before calling make it all lower/upper
    //and remove all special charecters and white spaces
    string temp = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            int x = 'a' - s[i];
            int n = s[i] - 'A';
            char ch = s[i] + x + n;
            s[i] = ch;
        }
        if(s[i] >= 'a' && s[i] <= 'z') temp += s[i];
        if(s[i] >= '1' && s[i] <= '9') temp += s[i];
    }
    return isPalindrome(0, temp.size()-1, temp);
}