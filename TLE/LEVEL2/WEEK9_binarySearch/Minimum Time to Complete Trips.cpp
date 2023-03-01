// https://leetcode.com/problems/minimum-time-to-complete-trips/description/
class Solution {
public:
    bool predicate(long long mid, vector<int>& time, int totalTrips) {
        long long trip = 0;
        for(auto &it : time) trip += (mid / it);
        return trip >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long L = -1, H = 1e14+1;
        while(H-L > 1) {
            long long mid = L + (H-L)/2;
            if(predicate(mid, time, totalTrips)) H = mid;
            else L = mid;
        }
        return H;
    }
};