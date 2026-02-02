//3010. Divide an Array Into Subarrays With Minimum Cost I
//https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
//Date: 02-02-2026

//first try - greedy approach
//works for given test cases but fails for some other cases
//time complexity: O(n), space complexity: O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        int a = 0;
        int b = 0;
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                ans = nums[i];
            }
            else{
                if(a == 0 || (nums[i] < nums[a] && i != b)){
                    a = i;
                }
                if(b == 0 || (nums[i] < nums[b] && i != a)){
                    b = i;
                }
            }
        }

        ans = ans + nums[a] + nums[b];

        return ans;
    }
};

//second try - finding first and second minimum elements in the array
//time complexity: O(n), space complexity: O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                ans = nums[i];
            }
            else{
                if(nums[i] < a){
                    b = a;
                    a = nums[i];
                }
                else if(nums[i] < b){
                    b = nums[i];
                }
            }
        }

        ans = ans + a + b;

        return ans;
    }
};

