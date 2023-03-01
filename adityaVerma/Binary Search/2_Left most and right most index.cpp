// https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool predicate2(long mid, vector<long long>& v, long long target) {
        return (v[mid] <= target);
    }

    bool predicate1(long mid, vector<long long>& v, long long target) {
        return (v[mid] < target);
    }

    long lastOccurrence(vector<long long>& v, long long x) {
        long L = -1, H = v.size();
        while(H-L > 1) {
            long mid = L + (H-L)/2;
            (predicate2(mid, v, x)) ? L = mid : H = mid;
        }
        if(L == -1 || v[L] != x) return -1;
        return L; // last true
    }

    long firstOccurrence(vector<long long>& v, long long x) {
        long L = -1, H = v.size();
        while(H-L > 1) {
            long mid = L + (H-L)/2;
            (predicate1(mid, v, x)) ? L = mid : H = mid;
        }
        if(H == v.size() || v[H] != x) return -1;
        return H; // first false
    }

    pair<long,long> indexes(vector<long long> v, long long x) {
        pair<long, long> ans;
        ans.first = firstOccurrence(v, x);
        ans.second = lastOccurrence(v, x);
        return ans;
    }
};