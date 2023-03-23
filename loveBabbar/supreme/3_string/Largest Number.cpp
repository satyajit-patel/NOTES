// https://leetcode.com/problems/largest-number/description/
class Solution {
public:
    static bool comp(std::string& s1, std::string& s2) {
        std::string temp1 = s1 + s2;
        std::string temp2 = s2 + s1;
        return temp1 > temp2;
    }

    string largestNumber(vector<int>& nums) {
        std::vector<std::string> snums;
        for(auto &it : nums) snums.push_back(std::to_string(it));

        std::sort(snums.begin(), snums.end(), comp);
        if(snums[0] == "0") return "0";

        std::string ans = "";
        for(auto &it : snums) ans += it;
        return ans;
    }
};