//66. Plus One
//https://leetcode.com/problems/plus-one/description/
//Date: 25-03-2026

//First try
// not working for all test cases
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] == 9 && n == 1){
            return {1,0};
        }
        if(digits[n-1] < 9){
            digits[n-1] = digits[n-1] + 1;
        }else{
            digits[n-2] = digits[n-2] + 1;
            digits[n-1] = 0;
        }

        return digits;
    }
};

//Second try
// working for all test cases
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;        
    }
};