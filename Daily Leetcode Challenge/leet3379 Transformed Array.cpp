//3379. Transformed Array
//https://leetcode.com/problems/transformed-array/
//Date: 05-02-2026

//Circular Array Index Mapping
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                int right = i + nums[i];
                right = ((right % n) + n) % n;
                result[i] = nums[right];

            }else if(nums[i] < 0){
                int left = i + nums[i];
                left = ((left % n) + n) % n;
                result[i] = nums[left];

            }
        }

        return result;
    }
};