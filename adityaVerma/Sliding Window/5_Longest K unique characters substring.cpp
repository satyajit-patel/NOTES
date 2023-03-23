// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution {
public:
    int longestKSubstr(string& s, int K) {
        int N = s.size();
        int len = -1;
        std::unordered_map<char, int> freq;
        int i=0, j = 0;
        while(i<N && j<N) {
            // calculation
            freq[s[j]]++;
            
            if(freq.size() < K) j++;
            else if(freq.size() == K) {
                len = std::max(len, j-i+1); // ans
                j++;
            }
            else if(freq.size() > K) {
                while(freq.size() > K) {
                    freq[s[i]]--;
                    if(freq[s[i]] == 0) freq.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return len;
    }
};