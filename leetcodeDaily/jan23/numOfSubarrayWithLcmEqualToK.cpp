//https://leetcode.com/contest/weekly-contest-319/problems/number-of-subarrays-with-lcm-equal-to-k/
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
    int lcm(int a, int b) {
        return (a*b)/gcd(a, b);
    }
    int subarrayLCM(vector<int>& nums, int k) {
        //given 1 <= n <= 1000
        //i.e we can write O(n^2) solution as we can have 10^8 operation per second default
        int hmm = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int curLcm = 1;
            for(int j=i; j<n; j++) {
                //a*b = lcm(a,b) * gcd(a,b);
                curLcm = lcm(curLcm, nums[j]);
                if(curLcm == k) hmm++;
                if(curLcm > k) break;
            }
        }
        return hmm;
    }
};