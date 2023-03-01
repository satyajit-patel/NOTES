// https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:	
    int findPivot(int* arr, int n) {
        int L = -1, H = n;
	    while(H-L > 1) {
	        int mid = L + (H-L)/2;
	        if(mid+1 < n && arr[mid] > arr[mid+1]) return mid;
	        if(mid-1 > 0 && arr[mid] < arr[mid-1]) return mid-1;
	        (arr[0] <= arr[mid]) ? L = mid : H = mid;
	    }
	    return -1;
    }

	int findKRotation(int arr[], int n) {
	    int pivot = findPivot(arr, n);
	    return pivot+1;
	}