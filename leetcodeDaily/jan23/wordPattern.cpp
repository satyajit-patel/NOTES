// https://leetcode.com/problems/word-pattern/description/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::vector<string> arr;
        string word;
        std::stringstream iss(s);
        while(iss >> word) arr.push_back(word);

        if(pattern.size() != arr.size()) return false;

        std::map<char, std::string> map; 
        for(int i=0; i<pattern.size(); i++) {
            if(map.find(pattern[i]) == map.end()) {
                // data redundancy (repeating same value)
                for(auto &it : map) {
                    if(arr[i] == it.second) return false;
                }
                map[pattern[i]] = arr[i];
            }
        }

        for(int i=0; i<pattern.size(); i++) {
            if(map[pattern[i]] != arr[i]) return false;
        }
        return true;
    }
};