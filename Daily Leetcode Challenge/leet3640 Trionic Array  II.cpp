//3640 Trionic Array  II
//https://leetcode.com/problems/trionic-array-ii/
//Date: 04-02-2026

//First try - Greedy / Single-pass 3-phase scan.
//failed on some edge cases
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MIN;
        int p = 0;
        int q = 0;
        int r = 0;

        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                l = i;
                break;
            } 
        }

        for(int i = l+1; i<n-1; i++){
            if(l > INT_MIN && nums[i] > nums[i+1]){
                p = i;
            }
            if(p > 0 && nums[i] < nums[i+1]){
                q = i;
            }
            if(q > 0 && nums[i] >= nums[i+1]){
                r = i;
            }
        }

        

        long long sum = 0;

        while(l <= r){
            sum = sum + nums[l];
            l++;
        } 

        return sum;
    }
};



//Second try - Greedy / Multi-pass scan.
// Passed all test cases
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int p, q, j;
        long long max_sum, sum, res;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;

            for (; j < n && nums[j - 1] < nums[j]; j++);
            p = j - 1;
            if (p == i) {
                continue;
            }
            res += nums[p] + nums[p - 1];

            for (; j < n && nums[j - 1] > nums[j]; j++) {
                res += nums[j];
            }
            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }
            res += nums[q + 1];

            max_sum = 0;
            sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            
            max_sum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            
            ans = max(ans, res);
            i = q - 1;
        }
        return ans;
    }
};