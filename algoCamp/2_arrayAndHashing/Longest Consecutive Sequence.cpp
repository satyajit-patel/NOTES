// https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, bool> hashMap;
        for(auto &it : nums) {
            if(hashMap.count(it-1) == false) hashMap[it] = true;
            else hashMap[it] = false;
            if(hashMap.count(it+1) == true) hashMap[it+1] = false;
        }
        int maxSize = 0;
        for(auto &it : hashMap) {
            if(it.second == true) {
                int startNum = it.first;
                int count = 0;
                while(hashMap.count(startNum+count) == true) count++;
                maxSize = std::max(maxSize, count);
            }
        }
        return maxSize;
    }
};