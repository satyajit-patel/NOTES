//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381889?leftPanelTab=0
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
//     set<int> s;
//     for(int i=0; i<n; i++) s.insert(arr[i]);
//     vector<int> vec;
//     for(auto &it : s) vec.push_back(it);
//     if(vec.size() == 1) return 1;
    
//     int count = 1;
//     int maxCount = INT_MIN;
//     for(int i=1; i<vec.size(); i++) {
//         if(vec[i] == vec[i-1]+1) count++;
//         else count = 1;
//         maxCount = max(maxCount, count);
//     }
//     return maxCount;
    
    
    unordered_set<int> s;
    int longestStreak = 0;
    for(int i=0; i<n; i++) s.insert(arr[i]);
    for(int i=0; i<n; i++) {
        if(s.count(arr[i]-1) == 0) {
            int curNumber = arr[i];
            int curStreak = 1;
            while(s.count(curNumber+1)) {
                curNumber += 1;
                curStreak += 1;
            }
            longestStreak = max(longestStreak, curStreak);
        }
    }
    return longestStreak;
}