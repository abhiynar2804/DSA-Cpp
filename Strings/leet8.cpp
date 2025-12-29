//8. String to Integer (atoi)

//by vs code
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Discard leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return static_cast<int>(sign * result);
    }
};