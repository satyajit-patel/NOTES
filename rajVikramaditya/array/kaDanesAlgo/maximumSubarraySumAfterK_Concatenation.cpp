//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381873?leftPanelTab=0
#include <bits/stdc++.h> 

long long kadane(vector<int> &arr, int n, int k) {
    long long maxSum = -1e15;
    long long curSum = 0; 
  
    for (int i = 0; i < n * k; i++) { 
        curSum += arr[i % n];   
        maxSum = max(maxSum, curSum);  
        if (curSum < 0) curSum = 0;
    } 
    return maxSum;
}

long long maxSubSumKConcat(vector<int> &arr, int n, int k) {
    
    //O(n * k)
    
//     vector<int> newArr;
//     for(int i=0; i<k; i++) {
//         newArr.insert(newArr.end(), arr.begin(), arr.end());
//     }
//     long long maxSum = INT_MIN;
//     long long sum = 0;
//     int M = int(1e9+7);
//     for(int i=0; i<newArr.size(); i++) {
//         sum += (newArr[i])%M;
//         maxSum = max(maxSum, sum);
//         if(sum < 0) sum = 0;
//     }
//     return maxSum;
    
    
    
    
    
    
//     long long maxSum = INT_MIN;
//     long long sum = 0;
//     for(int i=0; i<n * k; i++) {
//         sum += arr[i%n];
//         maxSum = max(maxSum, sum);
//         if(sum < 0) sum = 0;
//     }
//     return maxSum;
    
    
    
    
    
    //O(n)
    
    long long maxSum;
    if (k == 1) {
        maxSum = kadane(arr, n, k);
        return maxSum;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    if (sum <= 0) maxSum = kadane(arr, n, 2);   
    else {
        maxSum = kadane(arr, n, 2);
        maxSum += (long long)(k - 2) * (long long)sum;
       
    } 

    return maxSum;
    
    
    
    
    
    
}