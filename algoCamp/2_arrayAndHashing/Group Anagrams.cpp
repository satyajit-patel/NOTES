// https://leetcode.com/problems/group-anagrams/description/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> hashMap;
        /*
            arr["eat","tea","tan","ate","nat","bat"]
            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat
        */
        for(auto &it : strs) {
            std::string s = it;
            std::sort(s.begin(), s.end());
            hashMap[s].push_back(it);
        }
        std::vector<vector<string>> ans;
        for(auto &it : hashMap) ans.push_back(it.second);
        return ans;
        // tc :- given N strings and each are being sorted i.e O(N * KlogN) 
    }
};