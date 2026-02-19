//696. Count Binary Substrings
//https://leetcode.com/problems/count-binary-substrings/description/
//Date: 19 Feb 2026

//first try: brute force, fail in some test cases
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int zero = 0, one = 0;
        int ans;

        for(int i=0; i<n; i++){
            if(s[i] == '0') zero++;
            else one++;
        }

        if(zero == one){
            ans = (zero-1) * 2;
        }else{
            ans = min(zero, one)*2;
        }

        return ans;
    }
};

//second try: Consecutive Group Counting
class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero = 0;
        int one = 1;
        int ans = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                one++;
            } else {
                ans += min(zero, one);
                zero = one;
                one = 1;
            }
        }

        ans += min(zero, one);
        return ans;
    }
};
