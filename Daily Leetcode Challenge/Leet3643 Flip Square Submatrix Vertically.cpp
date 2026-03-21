//3643. Flip Square Submatrix Vertically
//https://leetcode.com/problems/flip-square-submatrix-vertically/
//Date: 21 Mar 2026

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k >> 1; i++)
            for (int j = 0; j < k; j++)
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);

        return grid;
    }
};
