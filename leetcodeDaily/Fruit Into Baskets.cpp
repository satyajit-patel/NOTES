// https://leetcode.com/problems/fruit-into-baskets/description/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int window = -1e9;
        unordered_map<int, int> map;
        for(int i=0,j=0; j<fruits.size(); j++) {
            map[fruits[j]]++;
            if(map.size() > 2) {
                map[fruits[i]]--;
                if(map[fruits[i]] == 0) map.erase(fruits[i]);
                i++;
            }
            window = std::max(window, j-i+1);
        }
        return window;
    }
};