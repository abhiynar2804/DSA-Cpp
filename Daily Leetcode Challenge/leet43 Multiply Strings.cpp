//43. Multiply Strings
//https://leetcode.com/problems/multiply-strings/
//Date: 28-01-2026

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> x;
        vector<int> y;

        for (char c : num1) x.push_back(c - '0');
        for (char c : num2) y.push_back(c - '0');

        vector<int> res(x.size() + y.size(), 0);

        // Multiply digits
        for (int i = x.size() - 1; i >= 0; i--) {
            for (int j = y.size() - 1; j >= 0; j--) {
                res[i + j + 1] += x[i] * y[j];
            }
        }

        // Handle carry
        for (int i = res.size() - 1; i > 0; i--) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }

        // Convert to string, skip leading zeros
        string ans;
        int start = 0;
        while (start < res.size() && res[start] == 0) start++;
        for (int i = start; i < res.size(); i++) ans += '0' + res[i];

        if (ans.empty()) return "0"; // if all zeros
        return ans;
    }
};
