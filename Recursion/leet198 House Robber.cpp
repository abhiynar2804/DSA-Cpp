//198. House Robber

//recursive approach
class Solution {
public:
    int robFrom(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        int rob = nums[i] + robFrom(nums, i + 2);
        int notRob = robFrom(nums, i + 1);
        return max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        return robFrom(nums, 0);
    }
};


//iterative approach
class Solution {
public:
    int rob(vector<int>& nums) {
        long prev2 = 0;  // dp[i-2]
        long prev1 = 0;  // dp[i-1]

        for (int money : nums) {
            long curr = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
