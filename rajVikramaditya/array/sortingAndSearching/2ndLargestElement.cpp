//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381890?leftPanelTab=1
#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr) {
//     set<int> s;
//     for(auto &it : arr) s.insert(it);
//     if(s.size() == 1) return -1;
//     auto it = s.rbegin();
//     it++;
//     return *it;
    
    
            //or
    set<int> s;
    for(auto &it : arr) s.insert(it);
    int max = *max_element(s.begin(), s.end());
    s.erase(max);
    if(s.size() == 0) return -1;
    max = *max_element(s.begin(), s.end());
    return max;
    
}