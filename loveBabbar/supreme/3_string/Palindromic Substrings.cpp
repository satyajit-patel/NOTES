// https://leetcode.com/problems/palindromic-substrings/description/
class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void f(int i, string s, int N, string temp, vector<string>& subsequence) {
        // base case
        if(i == N) {
            if(temp.size() != 0) subsequence.push_back(temp);
            return;
        }

        // recursive case
        temp += s[i];
        f(i+1, s, N, temp, subsequence);
        // backtrack
        temp.pop_back();
        f(i+1, s, N, temp, subsequence);
    }

    void g(string& s, int N, string& temp, vector<string>& substring) {
        for(int i=0; i<N; i++) {
            for(int j=i; j<N; j++) {
                temp += s[j];
                substring.push_back(temp);
            }
            temp.clear();
        }
    }

    int countSubstrings(string s) {
        int N = s.size();
        string temp = "";

        // std::vector<std::string> subsequence;
        // f(0, s, N, temp, subsequence);

        std::vector<std::string> substring;
        g(s, N, temp, substring);

        int ans = 0;
        // for(auto &it : substring) cout<<it<<" ";
	// O(N^3) approach
        for(auto &it : substring) { //------> N^2
            if(isPalindrome(it)) ans++; //-----> N
        }
        return ans;
    }
};