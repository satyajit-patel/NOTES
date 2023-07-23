// https://leetcode.com/problems/fibonacci-number/description/
class Solution {
public:
    int f(int n, std::vector<int>& dp) {
        // base case
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];

        int prev = f(n-1, dp);
        int prevPrev = f(n-2, dp);

        int ans = prev + prevPrev;
        dp[n] = ans;
        return ans;
    }
    int fib(int n) {
        std::vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};




// https://leetcode.com/problems/n-th-tribonacci-number/submissions/
class Solution {
public:
    int f(int n, vector<int>& dp) {
        //base case
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];

        int prev0   = f(n-1, dp);
        int prev1   = f(n-2, dp);
        int prev2   = f(n-3, dp);

        int ans = prev0 + prev1 + prev2;
        dp[n] = ans;
        return ans;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};



// https://leetcode.com/problems/climbing-stairs/description/
class Solution {
    public:
    int f(int i, int n, vector<int>& dp) {
        // base case
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];

        int oneStep = f(i+1, n, dp);
        int twoStep = f(i+2, n, dp);

        int ans = oneStep + twoStep;
        dp[i] = ans;
        return ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(0, n, dp);
    }
};




// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan&id=dynamic-programming-i
class Solution {
public:
    int f(int i, int n, vector<int>& cost, vector<int>& dp) {
        // base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = cost[i] + std::min(f(i+1, n, cost, dp), f(i+2, n, cost, dp));
        dp[i] = ans;
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int startWithIdx0 = f(0, n, cost, dp);
        int startWithIdx1 = f(1, n, cost, dp);
        return std::min(startWithIdx0, startWithIdx1);
    }
};


// ----------------------------------------------------------------------------------------------------------------- 


// https://leetcode.com/problems/house-robber/description/?envType=study-plan&id=dynamic-programming-i
class Solution {
public:
    int f(int i, int n, vector<int>& nums, vector<int>& dp) {
        //base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        //include
        int incl = nums[i] + f(i+2, n, nums, dp);
        //exclude
        int excl = 0 + f(i+1, n, nums, dp);

        int ans = std::max(incl, excl);
        dp[i] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return f(0, nums.size(), nums, dp);
    }
};




// https://leetcode.com/problems/house-robber-ii/description/
class Solution {
public:
    int f(int i, int n, vector<int>& arr, vector<int>& dp) {
        // base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        // include
        int incl = arr[i] + f(i+2, n, arr, dp);
        
        // exclude
        int excl = 0 + f(i+1, n, arr, dp);

        int ans = std::max(incl, excl);
        dp[i] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> arr1;
        vector<int> arr2;

        arr1.insert(arr1.begin(), nums.begin(), nums.end()-1);
        arr2.insert(arr2.begin(), nums.begin()+1, nums.end());

        vector<int> dp1(arr1.size()+1, -1);
        vector<int> dp2(arr2.size()+1, -1);

        return std::max(f(0, arr1.size(), arr1, dp1), f(0, arr2.size(), arr2, dp2));
    }
};



// https://leetcode.com/problems/delete-and-earn/description/
class Solution {
public:
    int f(int i, int n, std::vector<int>& arr, std::vector<int>& dp) {
        // base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        // include
        int incl = arr[i] + f(i+2, n, arr, dp);

        // exclude
        int excl = 0 + f(i+1, n, arr, dp);

        int ans = std::max(incl, excl);
        dp[i] = ans;
        return ans; 
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = *std::max_element(nums.begin(), nums.end());
        std::vector<int> arr(n+1, 0);
        for(auto &it : nums) arr[it] += it;

        std::vector<int> dp(arr.size()+1, -1);
        return f(0, arr.size(), arr, dp);
    }
};

// ---------------------------------------------------------------------------------------------------------------

                         // MEMOIZAION OF BOOLEAN FUNCTION


// https://leetcode.com/problems/jump-game/description/
class Solution {
public:
    bool f(int i, int n, vector<int>& nums, vector<int>& dp) {
        // base case
        if(i == n-1) return true;
        if(i >= n) return false;
        if(dp[i] != -1) return dp[i];

        int jumpCapacity = nums[i];
        bool ans = false;
        for(int jump=1; jump<=jumpCapacity; jump++) {
            ans = f(i + jump, n, nums, dp);
            if(ans == true) return true;
        }
        dp[i] = ans;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return f(0, nums.size(), nums, dp);
    }
};


// https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan&id=dynamic-programming-i
class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int i=0) {
        // base case
        if(i >= nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int ans  = 1e8;
        for(int j=1; j<=nums[i]; j++) {
            ans = std::min(ans, 1 + f(nums, dp, i+j));
        }
        dp[i] = ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return f(nums, dp);
    }
};


// -------------------------------------------------------------------------------------------------------------------


// https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int k(vector<int>& nums) {
        // kadane
        int sum = 0, maxSum = -1e9;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxSum = std::max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
    int maxSubArray(vector<int>& nums) {
        return k(nums);
    }
};


// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
class Solution {
public:
    int rk(vector<int>& nums) {
       // reverse kadane (prefix + suffix)
        int sum = 0, minSum = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            minSum = std::min(minSum, sum);
            if(sum > 0) sum = 0;
        }
        return minSum;
    }
    int k(vector<int>& nums) {
        // kadane
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxSum = std::max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        // kadane
        int maxSumSubarray = k(nums);
        if(maxSumSubarray < 0) return maxSumSubarray;

        // totSum   = prefix + subarray + suffix
        // subarray = totSum - minSumSubarray 
        int totSum = 0;
        for(auto &it : nums) totSum += it;
        int minSumSubarray = rk(nums);
        int subarray = totSum - minSumSubarray;
        return std::max(subarray, maxSumSubarray);
    }
};



// https://leetcode.com/problems/maximum-product-subarray/description/
class Solution {
public:
    int k(vector<int>& nums) {
        // kadane
        int sum = 1, maxSum = -1e9;
        for(int i=0; i<nums.size(); i++) {
            sum *= nums[i];
            maxSum = std::max(maxSum, sum);
            if(sum == 0) sum = 1;
        }
        return maxSum;
    }
    int maxProduct(vector<int>& nums) {
        int prodFromFront = k(nums); // -2, 5, 2 = -20
        std::reverse(nums.begin(), nums.end());
        int prodFromBack  = k(nums); // 2, 5, -2 = +10
        return std::max(prodFromFront, prodFromBack);
    }
};



// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/
class Solution {
public:
    int k(vector<int>& nums) {
        // kadane
        int sum = 1, maxLen = 0, len = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                sum *= nums[i]/std::abs(nums[i]);
                len++;
            }
            else {
                sum *= nums[i];
                len++;
            }
            if(sum > 0 && len > maxLen) maxLen = len;
            if(sum == 0) {
                sum = 1;
                len = 0;
            }
        }
        return maxLen;
    }
    int getMaxLen(vector<int>& nums) {
        int front = k(nums);
        std::reverse(nums.begin(), nums.end());
        int back = k(nums);

        return std::max(front, back);
    }
};


// -------------------------------------------------------------------------------------------------------------------


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
class Solution {
public:
    int f(int i, int n, int buy, vector<int> &val, vector<vector<int>> &dp) {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy) {
            int pick = -val[i] + f(i+1, n, !buy, val, dp);
            int notPick = 0 + f(i+1, n, buy, val, dp);
            profit = max(pick, notPick);
        }
        else {
            //we can't buy immediate aftre selling so we jump to next->next;
            int sell = val[i] + f(i+2, n, 1, val, dp);
            int notSell = 0 + f(i+1, n, 0, val, dp);
            profit = max(sell, notSell);
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, n, 1, prices, dp);
    }
};



// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/?envType=study-plan&id=dynamic-programming-i
class Solution {
public:
    
    int f(int i, int n, int buy, vector<int> &val, vector<vector<int>> &dp, int fee) {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy) {
            int pick = -val[i] + f(i+1, n, !buy, val, dp, fee);
            int notPick = 0 + f(i+1, n, buy, val, dp, fee);
            profit = max(pick, notPick);
        }
        else {
            //just pay the deliver charge here
            int sell = (val[i] - fee) + f(i+1, n, 1, val, dp, fee);
            int notSell = 0 + f(i+1, n, 0, val, dp, fee);
            profit = max(sell, notSell);
        }
        
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, n, 1, prices, dp, fee);
    }
};




// -------------------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------------------


