// https://leetcode.com/problems/verifying-an-alien-dictionary/description/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++) mapping[order[i] - 'a'] = i;
        for (auto &it : words) {
            for (auto &c : it) c = mapping[c - 'a'];
        }

        // for (auto &it : words) {
        //     for (auto &c : it) printf("%d", c);
        //     cout<<endl;
        // }

        return std::is_sorted(words.begin(), words.end());
    }
};