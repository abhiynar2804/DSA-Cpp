// Rat in a Maze - Backtracking
//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//submited Answer for geek for geeks
class Solution {
  public:
  
    bool isSafe(vector<vector<int>>& maze, int x, int y, int n,
                vector<vector<bool>> &visited) {
        return (x >= 0 && x < n && y >= 0 && y < n &&
                maze[x][y] == 1 && !visited[x][y]);
    }

    void solveMaze(vector<vector<int>>& maze, int n,
                   int x, int y,
                   vector<vector<bool>> &visited,
                   vector<string> &path,
                   string output)
    {
        // Destination reached
        if (x == n - 1 && y == n - 1) {
            path.push_back(output);
            return;
        }

        // D (Down)
        if (isSafe(maze, x + 1, y, n, visited)) {
            visited[x + 1][y] = true;
            solveMaze(maze, n, x + 1, y, visited, path, output + "D");
            visited[x + 1][y] = false;
        }

        // L (Left)
        if (isSafe(maze, x, y - 1, n, visited)) {
            visited[x][y - 1] = true;
            solveMaze(maze, n, x, y - 1, visited, path, output + "L");
            visited[x][y - 1] = false;
        }

        // R (Right)
        if (isSafe(maze, x, y + 1, n, visited)) {
            visited[x][y + 1] = true;
            solveMaze(maze, n, x, y + 1, visited, path, output + "R");
            visited[x][y + 1] = false;
        }

        // U (Up)
        if (isSafe(maze, x - 1, y, n, visited)) {
            visited[x - 1][y] = true;
            solveMaze(maze, n, x - 1, y, visited, path, output + "U");
            visited[x - 1][y] = false;
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> path;

        if (maze[0][0] == 0)
            return path;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        solveMaze(maze, n, 0, 0, visited, path, "");

        return path;
    }
};

//practice code for normal compiler
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int maze[][10], int x, int y, int rows, int cols, vector<vector<bool>> &visited) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1 && !visited[x][y]);
}

void solveMaze(int maze[][10], int rows, int cols,
               int x, int y,
               vector<vector<bool>> &visited,
               vector<string> &path,
               string output)
{
    if (x == rows - 1 && y == cols - 1) {
        path.push_back(output);
        return;
    }

    // DOWN
    if (isSafe(maze, x + 1, y, rows, cols, visited)) {
        visited[x + 1][y] = true;
        solveMaze(maze, rows, cols, x + 1, y, visited, path, output + "D");
        visited[x + 1][y] = false;
    }

    // RIGHT
    if (isSafe(maze, x, y + 1, rows, cols, visited)) {
        visited[x][y + 1] = true;
        solveMaze(maze, rows, cols, x, y + 1, visited, path, output + "R");
        visited[x][y + 1] = false;
    }

    // LEFT
    if (isSafe(maze, x, y - 1, rows, cols, visited)) {
        visited[x][y - 1] = true;
        solveMaze(maze, rows, cols, x, y - 1, visited, path, output + "L");
        visited[x][y - 1] = false;
    }

    // UP
    if (isSafe(maze, x - 1, y, rows, cols, visited)) {
        visited[x - 1][y] = true;
        solveMaze(maze, rows, cols, x - 1, y, visited, path, output + "U");
        visited[x - 1][y] = false;
    }
}


int main() {
    int maze[10][10] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    if(maze[0][0] == 0) {
        cout << "No paths available" << endl;
        return 0;
    }

    int rows = 4;
    int cols = 4;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, rows, cols, 0, 0, visited, path, output);

    cout << "Printing the paths: " << endl;
    for(auto i: path) {
        cout << i << endl;
    }

    if(path.size() == 0) {
        cout << "No paths available" << endl;
    }

    return 0;
}




//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//
//  Another Approach
// Alternative Implementation
//
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

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
