// https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string& s) {
        long long int num = 0, sign = 1, i = 0;
        while(s[i] == ' ') i++;
        if(i<s.size() && s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        int mx = INT_MAX;
        int mi = INT_MIN;
        while(i<s.size() && std::isdigit(s[i])) {
            // bcz INT_MAX == 2147483647 
            // i.e INT_MAX/10 == 214748364
            // so now we can't have digit more than '7, if we do it will exceed limit
            if(num > mx/10 || (num == mx/10 && s[i] > '7')) return (sign == -1) ? mi : mx;
            num = num * 10 + (s[i]-'0');
            i++;
        }
        return num * sign;
    }
};