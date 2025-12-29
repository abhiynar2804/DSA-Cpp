#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;

        // shrink window until its size becomes k
        while ((right - left + 1) > k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;   // remove left side
            } else {
                right--;  // remove right side
            }
        }

        // now elements from left to right are the answer
        vector<int> result;
        for (int i = left; i <= right; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
