// https://practice.geeksforgeeks.org/problems/max-rectangle/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    vector<int> nextSmallerElement(int* arr, int n) {
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = -1;
            st.push(i);
        }
        return nse;
    }
    
    vector<int> previousSmallerElement(int* arr, int n) {
        stack<int> st;
        vector<int> pse(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }
        return pse;
    }
    
    int getMaxArea(int arr[], int n) {
        vector<int> nse = nextSmallerElement(arr, n);
        vector<int> pse = previousSmallerElement(arr, n);
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nse[i] == -1) nse[i] = n;
            int Height = arr[i];
            int Base = nse[i] - pse[i] - 1;
            int Area = Height * Base;
            maxArea = std::max(maxArea, Area);
        }
        return maxArea;
    }

    int maxArea(int M[][MAX], int n, int m) {
        int maxArea = INT_MIN;
        int arr[m] = {0};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(M[i][j] != 0) arr[j] += M[i][j];
                else arr[j] = 0;
            }
            int Area = getMaxArea(arr, m);
            maxArea = std::max(maxArea, Area);
        }
        return maxArea;
    }
};
