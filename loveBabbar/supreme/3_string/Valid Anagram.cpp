// https://leetcode.com/problems/valid-anagram/description/
class Solution {
public:
    bool isAnagram(string& s, string& t) {
        // multiset<char> s1(s.begin(), s.end());
        // multiset<char> s2(t.begin(), t.end());
        // return s1 == s2;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(auto &it : s) freq1[it - 'a']++;
        for(auto &it : t) freq2[it - 'a']++;
        return freq1 == freq2;
    }
};