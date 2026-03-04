//1582. Special Positions in a Binary Matrix
//https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/
//Date: 04-03-2026

//Brute Force approach
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Count 1s in each row and column
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int ans = 0;
        
        // Check special positions
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};