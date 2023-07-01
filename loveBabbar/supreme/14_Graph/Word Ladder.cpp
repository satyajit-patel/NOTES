// https://leetcode.com/problems/word-ladder/description/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> st;
        for(auto &it : wordList) st.insert(it);
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()) {
            beginWord = q.front().first;
            int shortestDistance = q.front().second;
            q.pop();
            if(beginWord == endWord) return shortestDistance;
            for(int i=0; i<beginWord.size(); i++) {
                std::string temp = beginWord;
                for(char c='a'; c<='z'; c++) {
                    temp[i] = c;
                    if(st.count(temp)) {
                        q.push({temp, shortestDistance+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};