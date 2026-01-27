//9. Palindrome Number

//Recursive Approach
// Time Complexity: O(log10(n)) || Space Complexity: O(log10(n))
class Solution {
public:
    void solve(int x, int& ans){
        if(x == 0) return;

        ans = ans*10 + x % 10;
        solve(x/10, ans);
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        int ans = 0;
        solve(x,ans);
        if(x == ans) return true;
        return false;
    }
};

//Iterative Approach
//Time Complexity: O(log10(n)) || Space Complexity: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int original = x;
        long reversed = 0; 

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};

//String Approach
//Time Complexity: O(log10(n)) || Space Complexity: O(log10(n))
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