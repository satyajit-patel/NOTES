// https://leetcode.com/problems/reorganize-string/description/
class Solution {
public:
    string reorganizeString(string& s) {
        vector<int> hash(26, 0);
        for(int i=0; i<s.size(); i++) hash[s[i] - 'a']++;
        char maxFrequencyChar;
        int maxFrequency = INT_MIN;
        for(int i=0; i<26; i++) {
            if(hash[i] > maxFrequency) {
                maxFrequency = hash[i];
                maxFrequencyChar = i + 'a';
            }
        }
        int index = 0;
        while(maxFrequency>0 && index<s.size()) {
            s[index] = maxFrequencyChar;
            maxFrequency--;
            index += 2;
        }
        if(maxFrequency != 0) return "";

        // now place the rest of the char
        hash[maxFrequencyChar - 'a'] = 0;
        for(int i=0; i<26; i++) {
            while(hash[i] > 0) {
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};