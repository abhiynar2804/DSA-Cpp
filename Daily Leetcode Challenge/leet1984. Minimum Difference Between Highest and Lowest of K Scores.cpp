//1984. Minimum Difference Between Highest and Lowest of K Scores
//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
//Date - 25-01-2026

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = 0;
        int j = k;

        for (int i = 0; i <= nums.size()-k; i++){
            // solve(nums[i,k-1]);
            if(diff == 0 || nums[j-1] - nums[i] < diff){
                diff = nums[j-1] - nums[i];
            }
            if(j != nums.size()) j++;
        }
             

        return diff;
    }
};