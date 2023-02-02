// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1) 
            return str2.substr(0, std::gcd(str1.size(), str2.size()));
        return "";
    }
};