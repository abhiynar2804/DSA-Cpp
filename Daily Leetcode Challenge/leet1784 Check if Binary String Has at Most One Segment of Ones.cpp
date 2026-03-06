//1784. Check if Binary String Has at Most One Segment of Ones
//https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/
//Date: 06-03-2026

//first try : Brute Force
class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.length() == 1 && s[0] == '1') return true;
        for(int i=1; i<s.length(); i++){
            if(s[i] == '1' && s[i-1] == '1'){
                return true;
            }
        }

        return false;
    }
};

//second try : Two Pointer
class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        int i0=0;
        while(s[i0]=='1') i0++;
        if (i0==n) return 1;
        int i1=n-1;
        while(s[i1]=='0') i1--;
        return i0>i1;
    }
};