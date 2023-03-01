// https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
class Solution {
public:
    int prefixCount(vector<string>& words, string& pref) {
        int count = 0;
        for(auto &it : words) {
            string temp = it;
            int index = temp.find(pref);
            // if(index != string::npos) count++;
            // asking for leading contiguous substring
            if(index == 0) count++;
        }
        return count;
    }
};