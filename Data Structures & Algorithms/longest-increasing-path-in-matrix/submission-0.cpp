class Solution {
public:

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &longestDFS, int row, int col){
        
        if(longestDFS[row][col] != 0){
            return longestDFS[row][col]; 
        }

        int maxVal = 1; 

        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}; 

        for(auto [r,c]:dir){
            int nr = r+row; 
            int nc = c+col; 

            if(nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size()){
                if(matrix[nr][nc] > matrix[row][col]){
                    maxVal = max(maxVal, 1 + dfs(matrix, longestDFS, nr, nc)); 
                }
            }
        }
        longestDFS[row][col] = maxVal; 
        return maxVal; 
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        vector<vector<int>> longestDFS(n, vector<int> (m,0)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(matrix, longestDFS, i, j); 
            }
        }

        int res = INT_MIN; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = max(res, longestDFS[i][j]); 
            }
        }

        return res; 
    }
};
