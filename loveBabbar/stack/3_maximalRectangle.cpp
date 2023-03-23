//https://leetcode.com/problems/maximal-rectangle/submissions/
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
            //formula of width = index of its nse - index of pse its - 1;
            int width   = nse[i]-pse[i]-1;
            int area    = length*width;
            maxi = std::max(maxi, area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int> temp(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                //ie the flore is broke we can't add another floore above it
                if(matrix[i][j] == '0') temp[j] = 0;
                else temp[j] += 1;
            }
            int area = largestRectangleArea(temp);
            maxi = std::max(maxi, area);
        }
        return maxi;
    }
};