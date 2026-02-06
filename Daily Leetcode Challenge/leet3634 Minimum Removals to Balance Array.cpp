//3634. Minimum Removals to Balance Array
//https://leetcode.com/problems/minimum-removals-to-balance-array/
//Date: 06-02-2026

//Two Pointer Approach
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n; 
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (nums[i] > (long long)nums[j] * k) {
                j++;
            }
            
            ans = min(ans, n - (i - j + 1));
        }

        return ans;
    }
};
