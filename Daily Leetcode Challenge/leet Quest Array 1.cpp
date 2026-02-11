//Quest Array 1
//Date: 08-02-2026

//1929. Concatenation of Array
//http://leetcode.com/problems/concatenation-of-array/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);

        for(int i=0; i<n; i++){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }

        return ans;
    }
};


//1470. Shuffle the Array
//http://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            ans[2 * i]     = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }
        
        return ans;
    }
};


//645. Set Mismatch
//http://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(2);

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) ans[0] = i; // duplicate
            if (freq[i] == 0) ans[1] = i; // missing
        }

        return ans;
    }
};

