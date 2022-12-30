//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381872?leftPanelTab=0
#include <bits/stdc++.h> 
int flipBits(int* arr, int n) {
    int numOfOnes = 0;
    int newArr[n];
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) newArr[i] = 1;
        else {
            newArr[i] = -1;
            numOfOnes++;
        }
    }
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) {
        sum += newArr[i];
        if(sum < 0) sum = 0;
        maxSum = max(maxSum, sum);
    }
    return maxSum + numOfOnes;
}