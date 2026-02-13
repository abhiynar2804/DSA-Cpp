//912. Sort an Array
//https://leetcode.com/problems/sort-an-array/description/
//Date: 13-02-2026

//Approach: Merge Sort
//Time Complexity: O(n log n)
class Solution {
public:
    void merge(vector<int>& nums,vector<int>& temp, int start,int mid, int end){
        int i = start, j = mid + 1, k = start;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while(i <= mid) temp[k++] = nums[i++];
        while(j <= end) temp[k++] = nums[j++];
        
        while(start <= end){
            nums[start] = temp[start];
            start++;
        }
    }

    void mergeSort(vector<int>& nums,vector<int>& temp, int start, int end){
        if(start >= end) return;

        int mid = (start + end)/2;
        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid+1, end);

        merge(nums, temp, start, mid, end);

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        
        mergeSort(nums, temp, 0, n-1);

        return nums;
    }
};
