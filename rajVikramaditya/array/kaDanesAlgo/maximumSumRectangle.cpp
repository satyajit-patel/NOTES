//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381874
#include <bits/stdc++.h> 
int maxSumRectangle(vector<vector<int>>& arr, int n, int m) {
    int maxSum = INT_MIN;
    for(int k=0; k<n; k++) {
        vector<int> newArr(m, 0);
        for(int i=k; i<n; i++) {
            int sum = 0;
            for(int j=0; j<m; j++) {
                newArr[j] += arr[i][j];
                sum += newArr[j];
		maxSum = max(maxSum, sum);
                if(sum < 0) sum = 0;
            }
        }
    }
    return maxSum;
}
