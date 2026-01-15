// Rat in a Maze - Backtracking

#include <iostream>
using namespace std;
#include <vector>

// Recursive function to find all paths from (x,y) to destination
void solveMaze(int maze[][10], int rows, int cols, int x, int y, vector<vector<bool>> &visited, vector<string> &path, string &output) {
    // If we reached the end
    if (x == rows - 1 && y == cols - 1) {
        for (const string &step : path) {
            output += step + " ";
        }
        output += "\n";
        cout << output;
        return;
    }

    // Try all 4 directions: Down, Left, Right, Up
    int rowMoves[] = {1, 0, 0, -1};
    int colMoves[] = {0, -1, 1, 0};
    string directions[] = {"D", "L", "R", "U"};

    for (int i = 0; i < 4; i++) {
        int newX = x + rowMoves[i];
        int newY = y + colMoves[i];

        // Check if move is valid
        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
            maze[newX][newY] == 1 && !visited[newX][newY]) {

            visited[newX][newY] = true;
            path.push_back(directions[i]);

            solveMaze(maze, rows, cols, newX, newY, visited, path, output);

            // Backtrack
            visited[newX][newY] = false;
            path.pop_back();
        }
    }
}

int main(){
    // 1 = path, 0 = wall
    int maze[10][10] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int rows = 4;
    int cols = 4;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, rows, cols, 0, 0, visited, path, output);
    
    return 0;
}