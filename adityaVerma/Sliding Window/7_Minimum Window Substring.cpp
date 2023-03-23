// https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
    string minWindow(string& s, string& t) {
        if(t.size() > s.size()) return "";
        std::pair<int, std::pair<int, int>> window;
        window.first = INT_MAX; 
        int N = s.size();
        std::unordered_map<char, int> base;
        for(auto &it : t) base[it]++;
        int count = base.size();
        
        int i = 0;
        int j = 0;
        bool weGotNoAns = true;
        while(i<N && j<N) {
            // calculation
            if(base.find(s[j]) != base.end()) {
                base[s[j]]--;
                if(base[s[j]] == 0) count--;
            }

            if(count > 0) j++;
            else if(count == 0) {
                // ans
                weGotNoAns = false;
                if(j-i+1 < window.first) {
                    window.first = j-i+1;
                    window.second.first = i;
                    window.second.second = j;
                }

                // slide
                while(count == 0) {
                    if(base.find(s[i]) == base.end()) {
                        i++;
                        // ans
                        if(j-i+1 < window.first) {
                            window.first = j-i+1;
                            window.second.first = i;
                            window.second.second = j;
                        }
                    }
                    else {
                        base[s[i]]++;
                        if(base[s[i]] > 0) {
                            i++;
                            count++;
                        }
                        else {
                            i++;
                            // ans
                            if(j-i+1 < window.first) {
                                window.first = j-i+1;
                                window.second.first = i;
                                window.second.second = j;
                            }
                        }
                    }
                }
                j++;
            }
        }
        i = window.second.first;
        j = window.second.second;
        if(i > j) return "";
        if(weGotNoAns) return "";
        std::string temp = "";
        for(int x=i; x<=j; x++) temp += s[x];
        return temp;
    }
};