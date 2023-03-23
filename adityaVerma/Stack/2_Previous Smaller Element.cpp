// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1
class Solution {
public:
    vector<int> previousSmallerElement(int* arr, int n){
        stack<int> st;
        vector<int> pse(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] <= st.top()) st.pop();
            if(!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(arr[i]);
        }
        return pse;
    }
        
    vector<int> leftSmaller(int n, int a[]){
        return previousSmallerElement(a, n);
    }
};