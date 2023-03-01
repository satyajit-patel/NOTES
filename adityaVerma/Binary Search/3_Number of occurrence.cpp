// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:	
    bool predicate2(int mid, int* v, int target) {
        return (v[mid] <= target);
    }

    bool predicate1(int mid, int* v, int target) {
        return (v[mid] < target);
    }

    int lastOccurrence(int* v, int n, int x) {
        int L = -1, H = n;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            (predicate2(mid, v, x)) ? L = mid : H = mid;
        }
        if(L == -1 || v[L] != x) return -1;
        return L; // last true
    }

    int firstOccurrence(int* v, int n, int x) {
        int L = -1, H = n;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            (predicate1(mid, v, x)) ? L = mid : H = mid;
        }
        if(H == n || v[H] != x) return -1;
        return H; // first false
    }

    pair<int , int> indexes(int* v, int n, int x) {
        pair<int, int> ans;
        ans.first = firstOccurrence(v, n, x);
        ans.second = lastOccurrence(v, n, x);
        return ans;
    }

	int count(int arr[], int n, int x) {
	    int totalOccurrence = 0;
	    
	    pair<int, int> ans = indexes(arr, n, x);
	    if(ans.first == -1 || ans.second == -1) return totalOccurrence;
	    totalOccurrence = ans.second - ans.first + 1;
	    
        return totalOccurrence;
	}
};