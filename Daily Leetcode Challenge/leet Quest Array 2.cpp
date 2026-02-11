//Quest Array 2
//Date: 11-02-2026

//485. Max Consecutive Ones
//http://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int temp = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                temp++;
            }
            else{
                if(ans < temp){
                    ans = temp;
                }
                temp = 0;
            }
        }

        if(ans < temp){
            ans = temp;
        }

        return ans;
    }
};


//1365. How Many Numbers Are Smaller Than the Current Number
//http://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i] > nums[j]){
                    count++;
                }
            }
            ans[i] = count;
        }   

        return ans;
    }
};


//448. Find All Numbers Disappeared in an Array
//http://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

