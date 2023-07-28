// https://leetcode.com/problems/non-overlapping-intervals/description/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if we want to use other local variable other than passing parametre then
        // we need to pass & sign inside [] i.e [&] like this
        // this technique is called custom comparator using lamda function
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        int ped = INT_MIN;
        int total_include = 0;
        for(auto &row : intervals) {
            int st = row[0];
            int ed = row[1];
            if(st >= ped) {
                ped = ed;
                total_include++;
            }
        }
        return intervals.size() - total_include;
    }
};