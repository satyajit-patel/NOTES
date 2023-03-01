// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/
class Solution {
public:
    int minSteps(string& s, string& t) {
        vector<int> freq(26, 0);
        for(auto &it : s) freq[it - 'a']++;
        for(auto &it : t) freq[it - 'a']--;

        int count = 0;
        // now if ++ i.e thats much are char are present
        // if -- i.e we need to add those char on first side to make char equal
        for(auto &it : freq) count += std::abs(it);
        return count;
    }
};