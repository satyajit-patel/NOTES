// https://leetcode.com/problems/palindromic-substrings/description/
class Solution {
public:
    int expandAround(int i, int j, string& s, int N) {
        int count = 0;
        while(i >= 0 && j < N && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string& s) {
        int N = s.size();
        int count = 0;
        // O(N^2) approach
        for(int i=0; i<N; i++) {
            int oddSubstrings = expandAround(i, i, s, N);
            count += oddSubstrings;
            int evenSubstrings = expandAround(i, i+1, s, N);
            count += evenSubstrings;
        }
        return count;
    }