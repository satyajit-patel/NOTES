// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int longestKSubstr(string& s) {
        int N = s.size();
        int ans = 0;
        std::unordered_map<char, int> freq;
        int i=0, j = 0;
        while(i<N && j<N) {
            // calculation
            freq[s[j]]++;
            
            if(freq.size() == j-i+1) {
                int len = freq.size();
                ans = std::max(ans, len); // ans
                j++;
            }
            else if(freq.size() < j-i+1) {
                while(freq.size() < j-i+1) {
                    freq[s[i]]--;
                    if(freq[s[i]] == 0) freq.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }

    int lengthOfLongestSubstring(string& s) {
        return longestKSubstr(s);
    }
};