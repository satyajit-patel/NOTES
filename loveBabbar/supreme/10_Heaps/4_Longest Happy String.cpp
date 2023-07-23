// https://leetcode.com/problems/longest-happy-string/description/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        std::priority_queue<std::pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        std::string ans = "";
        while(maxHeap.size() >= 2) {
            int freq1 = maxHeap.top().first;
            char ch1 = maxHeap.top().second;
            maxHeap.pop();
            int freq2 = maxHeap.top().first;
            char ch2 = maxHeap.top().second;
            maxHeap.pop();

            if(freq1 >= 2) {
                ans += ch1;
                ans += ch1;
                freq1 -= 2;
            }
            else {
                ans += ch1;
                freq1 -= 1;
            }
            if(freq2 >= 2 && freq2 >= freq1) { // edge case
                ans += ch2;
                ans += ch2;
                freq2 -= 2;
            }
            else {
                ans += ch2;
                freq2 -= 1;
            }

            if(freq1 > 0) maxHeap.push({freq1, ch1});
            if(freq2 > 0) maxHeap.push({freq2, ch2});
        }
        if(!maxHeap.empty()) {
            int freq1 = maxHeap.top().first;
            char ch1 = maxHeap.top().second;
            maxHeap.pop();

            if(freq1 >= 2) {
                ans += ch1;
                ans += ch1;
                freq1 -= 2;
            }
            else {
                ans += ch1;
                freq1 -= 1;
            }
        }
        return ans;
    }
};