class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // Check for odd-length palindromes
        for (int center = 0; center < n; ++center) {
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        // Check for even-length palindromes
        for (int center = 0; center < n - 1; ++center) {
            int left = center, right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};