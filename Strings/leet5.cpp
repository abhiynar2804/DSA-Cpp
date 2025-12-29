//5. Longest Palindromic Substring

//by vs code
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int start = 0, maxLength = 1;

        for (int i = 0; i < n; ) {
            if (n - i <= maxLength / 2) break; // No longer palindrome possible

            int left = i, right = i;

            // Skip duplicate characters to handle even-length palindromes
            while (right < n - 1 && s[right] == s[right + 1]) right++;
            i = right + 1;

            // Expand around the center
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            int newLength = right - left + 1;
            if (newLength > maxLength) {
                start = left;
                maxLength = newLength;
            }
        }

        return s.substr(start, maxLength);
    }
};


//by supreme 3.0
class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for(int j=0; j < n; j++){
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > ans.size()) {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
    }
       return ans;
    }
};