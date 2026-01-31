//744. Find Smallest Letter Greater Than Target
//https://leetcode.com/problems/find-smallest-letter-greater-than-target/
//Date: 31-01-2026

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if((letters[0] - '0') > (target - '0')) return letters[0];
        int n = letters.size() - 1;
        if((letters[n] - '0') <= (target - '0')) return letters[0];

        int i = n;
        while(i >= 0){
            if(letters[i] <= target){
                return letters[i+1];
            }else{
                i--;
            }
        }

        return letters[0];
    }
};