//https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        /*
            strs = ["eat","tea","tan","ate","nat","bat"]
            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat
        */
        for(auto &it : strs) {
            string s = it;
            std::sort(s.begin(), s.end());
            m[s].push_back(it);
        }
        for(auto &it : m) {
            ans.push_back(it.second);
        }
        return ans;
    }
};