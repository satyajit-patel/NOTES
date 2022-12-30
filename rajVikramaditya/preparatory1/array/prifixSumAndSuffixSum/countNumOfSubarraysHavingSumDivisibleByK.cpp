//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381867?leftPanelTab=0
#include <bits/stdc++.h>
int subArrayCount(vector<int> &arr, int k) {
    int n = arr.size();
    long pSum[n];
    for(int i=0; i<n; i++) {
        if(i == 0) {
            pSum[i] = arr[i];
            continue;
        }
        pSum[i] = arr[i] + pSum[i-1];
    }
    unordered_map<int, int> m;
    m[0] = 1;
    int count = 0;
    for(int i=0; i<n; i++) {
        int r = pSum[i]%k;
        if(r < 0) r += k;
        if(m.find(r) != m.end()) count += m[r];
        m[r]++;
    }
    return count;
}
