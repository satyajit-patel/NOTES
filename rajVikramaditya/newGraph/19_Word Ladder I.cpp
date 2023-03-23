// https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        std::unordered_set<std::string> st(wordList.begin(), wordList.end());
        if(st.find(startWord) != st.end()) st.erase(startWord);
        std::queue<std::pair<std::string, int>> q;
        q.push({startWord, 1});
        
        while(!q.empty()) { // O(N)
            std::string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            
            for(int i=0; i<word.size(); i++) {
                char originalCh = word[i];
                for(char ch='a'; ch<='z'; ch++) { // O(26)
                    word[i] = ch;
                    if(st.find(word) != st.end()) { // O(1) or O(LogN)
                        st.erase(word); // mark it visited
                        q.push({word, steps+1});
                    }
                }
                word[i] = originalCh;
            }
        }
        return 0; // O(N * 26 * LogN)
    }
};