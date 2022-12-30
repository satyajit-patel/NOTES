//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381880
#include<bits/stdc++.h>
pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x) {
    //already given sorted array
    if(binary_search(arr.begin(), arr.end(), x)) {
        int idx1 = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int idx2 = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        return {idx1, idx2-1};
    }
    return {-1, -1};
}

