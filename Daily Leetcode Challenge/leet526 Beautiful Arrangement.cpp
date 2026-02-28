//526. Beautiful Arrangement
//https://leetcode.com/problems/beautiful-arrangement/
//Date: 28-02-2026

//backtracking
class Solution {
public:
    void countArrang(vector<int>& nums, int& n, int& ans, int currNum){
        if(currNum == n+1){
            ++ans;
            return;
        }

        for(int i=1; i<=n; ++i){
            if(nums[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                nums[i] = currNum;
                countArrang(nums, n, ans, currNum + 1);
                nums[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n+1);
        int ans = 0;
        countArrang(nums, n, ans, 1);
        return ans;
    }
};