//28. Find the Index of the First Occurrence in a String

//by me
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        return ans;
    }
};

//by vs code
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; ++i) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};