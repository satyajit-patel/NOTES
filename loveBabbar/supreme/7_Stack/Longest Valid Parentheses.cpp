// https://leetcode.com/problems/longest-valid-parentheses/description/
class Solution {
public:
    int longestValidParentheses(string s) {
        int hmm = 0;
        std::stack<int> st;
        st.push(-1);
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) hmm = std::max(hmm, i-st.top());
                else st.push(i);
            }
        }
        return hmm;
    }
};