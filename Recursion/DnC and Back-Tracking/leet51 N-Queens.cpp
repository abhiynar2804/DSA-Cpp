//51. N-Queens

class Solution {
public:

    unordered_set<int> leftRow;
    unordered_set<int> upperDiagonal;
    unordered_set<int> lowerDiagonal;

    void printSolution(vector<vector<char>>& board, vector<vector<string>>& ans, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output += board[i][j];
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<char>>& board, vector<vector<string>>& ans, int col, int n) {
        if (col >= n) {
            printSolution(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow.find(row) == leftRow.end() &&
                lowerDiagonal.find(row + col) == lowerDiagonal.end() &&
                upperDiagonal.find(n - 1 + col - row) == upperDiagonal.end()) {

                board[row][col] = 'Q';
                leftRow.insert(row);
                lowerDiagonal.insert(row + col);
                upperDiagonal.insert(n - 1 + col - row);

                solve(board, ans, col + 1, n);

                board[row][col] = '.';
                leftRow.erase(row);
                lowerDiagonal.erase(row + col);
                upperDiagonal.erase(n - 1 + col - row);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col = 0;

        solve(board, ans, col, n);

        return ans;
    }
};