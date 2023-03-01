// https://leetcode.com/problems/add-digits/description/
class Solution {
public:
    int addDigits(int num) {
        int sum  = 0;
        while(num) {
            int lastDigit = num % 10;
            sum += lastDigit;
            num /= 10;
        }
        string digit = std::to_string(sum);
        if(digit.size() == 1) return sum;
        else return addDigits(sum);
    }
};