//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#define vi vector<int>
class Solution {
public:
    void sub(int i, int n, int sum, vi &arr, vi &ans) {
        if(i == n) {
            ans.push_back(sum);
            return;
        }
        sum += arr[i];
        sub(i+1, n, sum, arr, ans);
        sum -= arr[i];
        sub(i+1, n, sum, arr, ans);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        vi ans;
        sub(0, N, 0, arr, ans);
        return ans;
    }
};