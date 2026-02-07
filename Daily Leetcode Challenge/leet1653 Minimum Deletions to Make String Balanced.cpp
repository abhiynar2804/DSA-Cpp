//1653. Minimum Deletions to Make String Balanced
//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
//Date: 07-02-2026

//Greedy Approach
class Solution {
public:
    int minimumDeletions(string s) {
        int bcount = 0;
        int ans = 0;

        for (char c : s) {
            if (c == 'b') {
                bcount++;
            } else {
                ans = min(ans + 1, bcount);
            }
        }
        return ans;
    }
};
