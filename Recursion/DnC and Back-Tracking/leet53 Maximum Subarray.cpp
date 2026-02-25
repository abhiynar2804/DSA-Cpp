//53. Maximum Subarray

//approach 1: divide and conquer
//time complexity: O(nlogn)
class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + ((end - start) >> 1);
        
        int maxLeftSum = helper(nums, start, mid);
        int maxRightSum = helper(nums, mid + 1, end);

        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i = mid; i>=start; i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }
        for(int i = mid + 1; i<=end; i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};