// https://leetcode.com/problems/concatenated-words/description/
class Solution {
public:
    bool isConcat(string& s, std::set<string>& set) {
        for(int i=1; i<s.size(); i++) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);
            if(set.count(prefix) && (set.count(suffix) || isConcat(suffix, set))) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        std::set<std::string> set;
        for(auto &it : words) set.insert(it);
        for(auto &it : words) if(isConcat(it, set)) ans.push_back(it);
        return ans; 
    }
};