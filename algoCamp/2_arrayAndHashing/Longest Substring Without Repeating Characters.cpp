// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int f(string& s) {
        std::unordered_map<char, int> hashMap;
        int i = 0, j = 0, ans = 0;
        while(j < s.size()) {
            // calculation
            hashMap[s[j]]++;

            if(hashMap.size() < j-i+1) {
                while(hashMap.size() < j-i+1) {
                    hashMap[s[i]]--;
                    if(hashMap[s[i]] == 0) hashMap.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if(hashMap.size() == j-i+1) {
                // update ans
                if(hashMap.size() > ans) ans = hashMap.size();
                j++;
            }
        }
        return ans;
    }

    int lengthOfLongestSubstring(string s) {
        return f(s);
    }
};