//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381882
#include <bits/stdc++.h> 
int bestInsertPos(vector<int> arr, int n, int m) {
    arr.push_back(m);
    sort(arr.begin(), arr.end());
    int idx = lower_bound(arr.begin(), arr.end(), m) - arr.begin();
    return idx;
}