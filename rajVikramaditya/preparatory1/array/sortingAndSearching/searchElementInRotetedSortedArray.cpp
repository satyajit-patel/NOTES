//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381878?leftPanelTab=1
int search(int* arr, int n, int key) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == key) return mid;
        //left half
        if(arr[mid] >= arr[low]) {
            if(key >= arr[low] && key <= arr[mid]) high = mid-1;
            else low = mid+1;
        }
        else {
            if(key >= arr[mid] && key <= arr[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}