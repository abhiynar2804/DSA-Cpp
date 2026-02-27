//1404. Number of Steps to Reduce a Number in Binary Representation to One
//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
//Date: 26-02-2026


//Greedy Approach
//Time Complexity: O(N)
//Space Complexity: O(1)
class Solution {
public:
    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        int carry = 0;
        for (int i = N - 1; i > 0; i--) {
            if (((s[i] - '0') + carry) % 2) {
                operations += 2;
                carry = 1;
            } else {
                operations++;
            }
        }

        return operations + carry;
    }
};