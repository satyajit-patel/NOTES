//https://leetcode.com/problems/distribute-repeating-integers/
class Solution {
public:
    bool f(int i, vector<int>& quantity, unordered_map<int, int>& m) {
        //baseCase
        if(i == quantity.size()) return true;
        
        for(auto &it : m) {
            if(it.second >= quantity[i]) {
                it.second -= quantity[i];
                if(f(i+1, quantity, m) == true) return true;
                
                //backtrac
                it.second += quantity[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> m;
        for(auto &it : nums) m[it]++;
        sort(quantity.begin(), quantity.end(), greater<int>());
        return f(0, quantity, m);
    }
};