//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
public:
    vector<int> NSE(vector<int>& A) {
        stack<int> s;
        vector<int> nse(A.size(), -1);
        for(int i=A.size()-1; i>=0; i--) {
            while(!s.empty() && A[s.top()] >= A[i]) s.pop();
            if(!s.empty()) nse[i] = s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int>& A) {
        stack<int> s;
        vector<int> pse(A.size(), -1);
        for(int i=0; i<A.size(); i++) {
            while(!s.empty() && A[s.top()] >= A[i]) s.pop();
            if(!s.empty()) pse[i] = s.top();
            s.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int maxi = INT_MIN;
        for(int i=0; i<heights.size(); i++) {
            int length  = heights[i];
            //edge case : if all the elements are same
            if(nse[i] == -1) nse[i] = heights.size();
            //formula of width = index of its nse - index of its pse - 1;
            int width   = nse[i]-pse[i]-1;
            int area    = length*width;
            maxi = std::max(maxi, area);
        }
        return maxi;
    }
};