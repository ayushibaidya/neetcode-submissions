class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j){
        int n = grid.size(); 
        int m = grid[0].size(); 
        vis[i][j] = 1; 

        // Up
        if(i - 1 >= 0 && grid[i - 1][j] == '1' && vis[i - 1][j] == 0){
            dfs(grid, vis, i - 1, j); 
        }
        // Right
        if(j + 1 < m && grid[i][j + 1] == '1' && vis[i][j + 1] == 0){
            dfs(grid, vis, i, j + 1); 
        }
        // Down
        if(i + 1 < n && grid[i + 1][j] == '1' && vis[i + 1][j] == 0){
            dfs(grid, vis, i + 1, j); 
        }
        // Left
        if(j - 1 >= 0 && grid[i][j - 1] == '1' && vis[i][j - 1] == 0){
            dfs(grid, vis, i, j - 1); 
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        int islands = 0; 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid, vis, i, j); 
                    islands++;
                }
            }
        }
        return islands; 
    }
};
