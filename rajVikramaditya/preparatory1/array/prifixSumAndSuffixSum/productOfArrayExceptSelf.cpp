//https://leetcode.com/problems/product-of-array-except-self/submissions/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        
        int left[n], right[n];
        for(int i=0; i<n; i++) {
            if(i == 0) {
                left[i] = arr[i];
                continue;
            }
            left[i] = arr[i] * left[i-1];
        }
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) {
                right[i] = arr[i];
                continue;
            }
            right[i] = arr[i] * right[i+1];
        }
        
        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[i] = right[i+1];
                continue;
            }
            if(i == n-1) {
                ans[i] = left[i-1];
                continue;
            }
            ans[i] = left[i-1] * right[i+1];
        }
        return ans;
    }
};