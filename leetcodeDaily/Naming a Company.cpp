// https://leetcode.com/problems/naming-a-company/description/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        std::unordered_map<std::string, int> map;
        for(auto &it : ideas) map[it]++;
        std::vector<std::vector<int>> alphabet(26, std::vector<int>(26, 0));
        for(auto &it : ideas) {
            std::string temp = it;
            char ch1 = temp[0];
            for(char j='a'; j<='z'; j++) {
                char ch2 = j;
                temp[0]  = ch2;
                if(map.find(temp) == map.end()) alphabet[ch1-'a'][ch2-'a']++;
            }
        }
        long long ans = 0;
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) ans += alphabet[i][j] * alphabet[j][i];
        }
        return ans;
    }
};