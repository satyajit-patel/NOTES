// https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
class Solution {
public:
    int MOD = 1e9 + 7;
    long long getHash(string& s) {
        long long h = 0;
        for(auto &ch : s) h = ((h * 31) + (ch - 'a' + 1)) % MOD;
         return h;
    }
    
    int prefixCount(vector<string>& words, string& pref) {
        int count = 0;
        long long h1 = getHash(pref);
        for(auto &it : words) {
            string s = it;
            string requiredTerm = s.substr(0, pref.size());
            long long h2 = getHash(requiredTerm);
            if(h1 == h2) count++;
        }
        return count;
    }
};