// https://leetcode.com/problems/minimum-time-difference/description/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int N = timePoints.size();
        std::vector<int> minutes;
        for(int i=0; i<N; i++) {
            std::string cur = timePoints[i];
            int Hours = std::stoi(cur.substr(0, 2));
            int Minut = std::stoi(cur.substr(3, 2));
            int totalMinut =  Hours * 60 + Minut;
            minutes.push_back(totalMinut);
        }

        int minDiff = INT_MAX;
        // sort so that we only have to campare the adjacent 
        std::sort(minutes.begin(), minutes.end());
        for(int i=0; i<N-1; i++) {
            int curDiff = minutes[i+1] - minutes[i];
            minDiff = std::min(curDiff, minDiff);
        }

        // edge case : compare between last and first
        int lastDiff = (minutes[0] + 1440) - minutes[N-1];
        minDiff = std::min(lastDiff, minDiff);

        return minDiff;
    }
};