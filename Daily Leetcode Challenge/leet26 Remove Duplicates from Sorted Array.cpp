//26. Remove Duplicates from Sorted Array
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
//Date: 02-01-2026

//Two Pointers approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;        
    }
};