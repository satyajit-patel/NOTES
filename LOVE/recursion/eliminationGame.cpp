//https://leetcode.com/problems/elimination-game/
class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) return n;
        return 2 * ((n/2) - lastRemaining(n/2) + 1);
    }
};