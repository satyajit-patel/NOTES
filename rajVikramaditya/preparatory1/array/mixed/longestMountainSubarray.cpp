//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376554?leftPanelTab=1
#include <bits/stdc++.h> 
int longestMountain(int *arr, int n) {
    if(n == 1 || n == 2) return 0;
    int maxi = 0;
    for(int i=1; i<n-1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int x = i, y = i;
            while(x > 0 && arr[x] > arr[x-1]) x--;
            while(y < n-1 && arr[y] > arr[y+1]) y++;
            int len = y-x+1;
            maxi = max(maxi, len);
        }
    }
    return maxi;
}