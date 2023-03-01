// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool predicate(int mid, int target, int* arr) {
        return (arr[mid] <= target);
    }

    int binarysearch(int arr[], int n, int k) {
        int L = -1, H = n;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            (predicate(mid, k, arr)) ? L = mid : H = mid;
        }
        if(L == -1 || arr[L] != k) return -1;
        return L;
    }
};