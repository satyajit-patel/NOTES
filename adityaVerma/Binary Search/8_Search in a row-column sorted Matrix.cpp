// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool search(vector<vector<int> > matrix, int n, int m, int x) {
        for(auto &row : matrix) {
            vector<int> arr = row;
            if(std::binary_search(arr.begin(), arr.end(), x)) return true;
        }
        return false;
    }
};