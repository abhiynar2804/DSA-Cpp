//3637. Trionic Array I
//https://leetcode.com/problems/trionic-array-i/
//Date: 03-02-2026


//first try - Greedy / single-pass heuristic
//work well but fail when extra direction changes
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p = false;
        bool q = false;
        bool last = false;
        for(int i=1; i<nums.size(); i++){
            if(p == false && nums[i] > nums[i-1]){
                p = true;
            }
            if(p == true && nums[i] < nums[i-1]){
                q = true;
            }
            if(q == true && nums[i] > nums[i-1]){
                last = true;
            }
        }

        if(p == true && q == true && last == true){
            return true;
        }

        return false;
    }
};

//second try - Greedy / Single-pass 3-phase scan.
// Passed all text casses
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums.size() < 4) return false;

        bool p = false, q = false, last = false;
        int i = 1;

        for (; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return false;
            if (nums[i] > nums[i-1]) p = true;
            else break;
        }

        for (; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return false;
            if (nums[i] < nums[i-1]) q = true;
            else break;
        }

        for (; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return false;
            if (nums[i] < nums[i-1]) return false; // 🔑 key fix
            last = true;
        }

        return p && q && last;
    }
};
