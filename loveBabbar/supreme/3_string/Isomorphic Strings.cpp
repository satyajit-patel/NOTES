// https://leetcode.com/problems/isomorphic-strings/description/
class Solution {
public:
    bool isIsomorphic(string& s, string& t) {
        int N = s.size();
        vector<int> hash(256);
        vector<bool> istMapped(256, false);
        for(int i=0; i<N; i++) { // O(N)
            if(hash[s[i]] == 0 && istMapped[t[i]] == false) {
                hash[s[i]] = t[i];
                istMapped[t[i]] = true;
            }
        }
        for(int i=0; i<N; i++) { // O(N)
            if((char)hash[s[i]] != t[i]) return false;
        }
        // overal TC = O(N)
        return true;
    }
};