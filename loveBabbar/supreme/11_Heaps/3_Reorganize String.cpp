// https://leetcode.com/problems/reorganize-string/description/
class Solution {
public:
    string reorganizeString(string s) {
        // make freq map -> make heap -> then pick 2 unique ele and add it to ans

        std::unordered_map<char, int> freq;
        for(auto &it : s) freq[it]++;

        std::priority_queue<std::pair<int, char>> maxHeap;
        for(auto &it : freq) maxHeap.push({it.second, it.first});

        std::string ans = "";
        while(maxHeap.size() >= 2) {
            int freq1 = maxHeap.top().first;
            char ch1 = maxHeap.top().second;
            maxHeap.pop();

            int freq2 = maxHeap.top().first;
            char ch2 = maxHeap.top().second;
            maxHeap.pop();

            ans += ch1;
            ans += ch2;
            freq1--;
            freq2--;

            if(freq1 != 0) maxHeap.push({freq1, ch1});
            if(freq2 != 0) maxHeap.push({freq2, ch2});
        }
        if(!maxHeap.empty()) {
            int freq1 = maxHeap.top().first;
            char ch1 = maxHeap.top().second;
            maxHeap.pop();
            if(freq1 == 1) ans += ch1;
            else return "";
        }
        return ans;
    }
};