// https://leetcode.com/problems/find-k-closest-elements/description/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int N = arr.size();
        // 2 pointer approach
        int i = 0, j = N-1;
        while((j-i+1) != k) {
            if((x - arr[i]) > (arr[j] - x)) i++;
            else j--;
        }
        std::vector<int> ans;
        ans.insert(ans.begin(), arr.begin()+i, arr.begin()+j+1);
        return ans;
    }
};