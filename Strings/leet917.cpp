// 917. Reverse Only Letters

// by vs code
class Solution {
public:
    bool isalpha(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (!isalpha(s[i])) {
                i++;
            } else {
                j--;
            }
        }
        return s;
    }
};