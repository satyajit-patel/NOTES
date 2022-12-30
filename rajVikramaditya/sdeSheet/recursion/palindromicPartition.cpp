//https://leetcode.com/problems/palindrome-partitioning/submissions/
#define vs vector<string>
#define vvs vector<vector<string>>
class Solution {
public:
    bool isPalindrome(int low, int high, string s) {
        while(low <= high) {
            if(s[low++] != s[high--]) return false;
        }
        return true;
        // s = s.substr(low, high-low+1);
        // string tmp = s;
        // reverse(tmp.begin(), tmp.end());
        // if(tmp == s) return true;
        // return false;
    }
    void sub(int i, string s, vs &ds, vvs &ans) {
        if(i == s.size()) {
            ans.push_back(ds);
            return;
        }
        for(int ind=i; ind<s.size(); ind++) {
            if(isPalindrome(i, ind, s)) {
                ds.push_back(s.substr(i, ind-i+1));
                sub(ind+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vvs ans; vs ds;
        sub(0, s, ds, ans);
        return ans;
    }
};