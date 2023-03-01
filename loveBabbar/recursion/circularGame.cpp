//https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/
class Solution {
public:
    int f(int n, int k) {
        //baseCase
        if(n == 1) return 0;
        
        //recursiveCase
        return (f(n-1, k)+k) % n;
    }
    int findTheWinner(int n, int k) {
        return f(n, k) + 1; //+1 because it's 1based indexing
    }
};