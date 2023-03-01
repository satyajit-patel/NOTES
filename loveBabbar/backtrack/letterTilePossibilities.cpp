// https://leetcode.com/problems/letter-tile-possibilities/submissions/
class Solution {
public:
    void f(string& s, set<string>& set, string& temp, map<int, int>& map) {
        for(int i=0; i<s.size(); i++) {
            if(!map[i]) {
                
                map[i] = 1;
                temp += s[i];
                set.insert(temp);
                f(s, set, temp, map);
                
                
                //backtrack
                map[i] = 0;
                temp.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> set;
        map<int, int> map;
        string temp = "";
        f(tiles, set, temp, map);
        for(auto &it : set) cout<<it<<" ";
        return set.size();
    }
};