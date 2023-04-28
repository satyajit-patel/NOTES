//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n) {
    long long sum = 0, maxSum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum < 0) sum = 0;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}