//Quest Math
//Arithmetic and basic math problems
//Date: 14-02-2026


//Q1. Can Make Arithmetic Progression From Sequence
//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/

//First try: Sorting and checking the difference between consecutive elements
//Time Complexity: O(n log n)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int diff = 0;
        sort(arr.begin(), arr.end());

        for(int i=0; i<arr.size()-1; i++){
            int dif = arr[i] - arr[i+1];
            if(diff == dif) return true;
            diff = dif;
        }

        return false;
    }
};

//Second try: Sorting and checking the difference between consecutive elements
//Time Complexity: O(n log n)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int diff = arr[1] - arr[0];
        for (int i = 2; i < n; i++) {
            if (arr[i] - arr[i-1] != diff) return false;
        }
        return true;
    }
};




//Q2. Find the Pivot Integer
//https://leetcode.com/problems/find-the-pivot-integer/description/
//First try: Two pointer approach
//Time Complexity: O(n)
class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;
        int j = n;
        int right = 0;
        int left = 0; 

        while(i <= j){
            if(right >= left){
                left = left + i;
                i++;
            }
            if(right < left){
                right = right + j;
                j--;
            }
        }

        if(right == left) return i-1;

        return -1;
    }
};

//second try: Mathematical approach
//Time Complexity: O(1)
class Solution {
public:    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2; 
        int leftSum = 0;

        for (int i = 1; i <= n; i++) {
            leftSum += i; 
            if (leftSum == sum - leftSum) {
                return i; 
            }
        }

        return -1; 
    }
};

//third try: Mathematical approach using square root
//Time Complexity: O(1)
class Solution {
public:
    int pivotInteger(int n) {
        long long total = 1LL * n * (n + 1) / 2;   
        
        int x = sqrt(total);                       
        if (1LL * x * x == total) 
            return x;
        
        return -1;
    }
};




//Q3. Palindrome Number
//https://leetcode.com/problems/palindrome-number/description/

//First try: Converting the number to string and checking if it is a palindrome
//Time Complexity: O(n)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string ans = to_string(x);
        int l = 0;
        int r = ans.length() - 1;
        while (l < r) {
            if (ans[l] != ans[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

//Second try: Reversing the number and checking if it is a palindrome
//Time Complexity: O(n)
class Solution {
public:    bool isPalindrome(int x) {
        if (x < 0) return false;
        int original = x;
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};