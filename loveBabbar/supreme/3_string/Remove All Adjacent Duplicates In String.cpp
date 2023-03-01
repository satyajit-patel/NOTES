// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
class Solution {
public:
    string removeDuplicates(string& s) {
        std::string ans = "";
        for(auto &it : s) {
            if(it != ans.back()) ans += it;
            else ans.erase(ans.size()-1);
        }
        return ans;
    }
};