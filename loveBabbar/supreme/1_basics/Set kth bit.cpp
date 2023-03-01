// https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int my_pow(int base, int power) {
        int ans = 1;
        while(power) {
            if(power&1) ans *= base;
            base *= base;
            power >>= 1;
        }
        return ans;
    }
    int setKthBit(int N, int K) {
        bitset<16> bs(N);
        bs[K] = 1;
        string temp = bs.to_string();
        int ans = 0;
        std::reverse(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++) {
            if(temp[i] == '1') {
                // ans += std::pow(2, i);
                ans += my_pow(2, i);
            }
        }
        return ans;
    }
    
};
