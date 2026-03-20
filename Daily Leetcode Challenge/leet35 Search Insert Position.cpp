//35. Search Insert Position
//https://leetcode.com/problems/Search-insert-position/
//Date: 20-03-2026

//Two Pointer Aprroach
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return left;
    }
};
