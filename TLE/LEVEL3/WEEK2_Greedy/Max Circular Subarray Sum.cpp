// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
class Solution{
    public:
    int kadane(int* A, int N) {
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<N; i++) {
            sum += A[i];
            if(sum < 0) sum = 0;
            maxi = std::max(maxi, sum);
        }
        return maxi;
    }
    
    int reverseKadane(int* A, int N) {
        int sum = 0, mini = INT_MAX;
        for(int i=0; i<N; i++) {
            sum += A[i];
            if(sum > 0) sum = 0;
            mini = std::min(mini, sum);
        }
        return mini;
    }
    
    int circularSubarraySum(int arr[], int num){
        int maxi = *std::max_element(arr, arr+num);
        if(maxi < 0) return maxi;
        else maxi = kadane(arr, num);
        int total = 0;
        for(int i=0; i<num; i++) total += arr[i];
        int mini = reverseKadane(arr, num);
        return std::max(maxi, total-mini);
    }
};