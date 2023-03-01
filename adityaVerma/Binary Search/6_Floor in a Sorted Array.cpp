// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
    bool predicate(long long mid, long long target, vector<long long>& v) {
        return (v[mid] <= target);
    }
  
    int findFloor(vector<long long>& v, long long n, long long x) {
        long long L = -1, H = n;
        while(H-L > 1) {
            long long mid = L + (H-L)/2;
            (predicate(mid, x, v)) ? (L = mid) : (H = mid);
        }
        return L;
    }
};