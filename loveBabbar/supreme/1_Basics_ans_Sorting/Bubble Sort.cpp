// https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_articlehttps://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_articlehttps://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    void bubbleSort(int arr[], int n) {
        for(int i=0; i<n; i++) {
            int swap = 0;
            for(int j=0; j<n-1-i; j++) {
                if(arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                    swap++;
                }
            }
            if(swap == 0) return;
        }
    }
};