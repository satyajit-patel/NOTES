// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    vector<int> nextSmallerElement(vector<int>& arr, int n){
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] <= st.top()) st.pop();
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = -1;
            st.push(arr[i]);
        }
        return nse;
    }

    vector<int> help_classmate(vector<int>& arr, int n) { 
        return nextSmallerElement(arr, n);
    } 
};