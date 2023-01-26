// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    } 
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.size() == 0) return 0;

        // [[10,16],[2,8],[1,6],[7,12]]
        // sortaccording to 2nd ele(end points) so that overlaping line will come together
        std::sort(points.begin(), points.end(), comp); // O(NlogN);
        // after sort : [[1,6],[2,8][7,12],[10,16]]

        // initially
        int numOfArrow = 1;
        int iskiPetPeBandMariyePravu = points[0][1];
        for(int i=1; i<points.size(); i++) {
            int startPoint = points[i][0];
            int endPoint   = points[i][1];
            if(startPoint <= iskiPetPeBandMariyePravu) continue;
            else {
                numOfArrow++;
                iskiPetPeBandMariyePravu = endPoint;
            }
        }
        return numOfArrow;
    }
};