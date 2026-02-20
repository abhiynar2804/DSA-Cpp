//3760. Maximum Substrings With Distinct Start
//https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/
//Date: 20 Feb 2026


//approach: count the number of distinct characters in the string, which is the maximum number of substrings with distinct start characters
class Solution {
public:
    int maxDistinct(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        int cnt = 0;
        for(auto i:s){
            if(freq[i-'a'] == 0) {
                cnt++;
            }
            freq[i-'a']++;
        }
        return cnt;
    }
};