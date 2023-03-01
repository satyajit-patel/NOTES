// https://practice.geeksforgeeks.org/problems/index-of-first-1-in-a-sorted-array-of-0s-and-1s4048/1
class Solution {
public:
    bool predicate(int mid, int* arr) {
        return (arr[mid] < 1);
    }

    int binarySearchApproach(int* arr, int n) {
        int L = -1, H = n;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            (predicate(mid, arr)) ? (L = mid) : (H = mid);
        }
        if(H == n || arr[H] != 1) return -1;
        return H;
    }

    int stringApproach(int* arr, int n) {
        string temp = "";
        for(int i=0; i<n; i++) temp += std::to_string(arr[i]);
        int index = temp.find_first_of('1');
        if(index != n) return index;
        return -1;
    }
    
    int firstIndex(int a[], int n) {
        // return stringApproach(a, n); // O(N) TLE
        return binarySearchApproach(a, n); // O(Log(N))
    }
};