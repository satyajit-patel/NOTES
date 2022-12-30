//https://leetcode.com/problems/k-th-symbol-in-grammar/
class Solution {
public:
    int kthGrammar(int n, int k) {
        //baseCase
        if(n == 1) return 0;
        
        //recursiveCase
        int parentOfK = kthGrammar(n-1, k/2 + k%2);
        if(parentOfK == 0) {
            if(k%2 == 0) return 1;
            return 0;
        }
        else {
            if(k%2 == 0) return 0;
            return 1;
        }
    }
};