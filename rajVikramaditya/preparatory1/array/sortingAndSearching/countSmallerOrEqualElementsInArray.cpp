//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381881?leftPanelTab=0
#include <bits/stdc++.h> 
vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    vector<int> ans;
    sort(b, b+m);
    for(int i=0; i<n; i++) {
        int x = 0;
        int idx = upper_bound(b, b+m, a[i]) - b;
        idx = idx-1;
        x = idx - 0 + 1;
        ans.push_back(x);
    }
    return ans;
}