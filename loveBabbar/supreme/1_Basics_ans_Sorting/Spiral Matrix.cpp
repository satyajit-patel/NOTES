// https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int curSize = 0;
        int totSize = n * m;

        int firstRow = 0;
        int firstColumn = 0;
        int lastRow = n-1;
        int lastColumn = m-1;
        while(curSize < totSize) {
            for(int j=firstColumn; j<=lastColumn && curSize<totSize; j++) {
                ans.push_back(matrix[firstRow][j]);
                curSize += 1;
            }
            firstRow += 1;
            for(int i=firstRow; i<=lastRow && curSize<totSize; i++) {
                ans.push_back(matrix[i][lastColumn]);
                curSize += 1;
            }
            lastColumn -= 1;
            for(int j=lastColumn; j>=firstColumn && curSize<totSize; j--) {
                ans.push_back(matrix[lastRow][j]);
                curSize += 1;
            }
            lastRow -= 1;
            for(int i=lastRow; i>=firstRow && curSize<totSize; i--) {
                ans.push_back(matrix[i][firstColumn]);
                curSize += 1;
            }
            firstColumn += 1;
        }
        return ans; 
    }
};