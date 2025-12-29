#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;  // absolute difference can't be negative

        sort(nums.begin(), nums.end());  // sort array first
        int n = nums.size();

        int left = 0; 
        int right = 1;
        int count = 0;

        while (right < n) {
            // avoid comparing same index
            if (left == right) {
                right++;
                continue;
            }

            int diff = nums[right] - nums[left];

            if (diff == k) {
                count++;
                left++;
                right++;

                // skip duplicates for left pointer
                while (right < n && nums[right] == nums[right - 1]) {
                    right++;
                }
            }
            else if (diff < k) {
                right++;   // increase difference
            }
            else { // diff > k
                left++;    // decrease difference
            }
        }

        return count;
    }
};
