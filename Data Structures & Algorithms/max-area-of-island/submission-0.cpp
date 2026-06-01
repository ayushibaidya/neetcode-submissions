class Solution {
public:

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int &dfsArea){
        int n = grid.size(); 
        int m = grid[0].size(); 
        vis[i][j] = 1; 

        if(i-1 >= 0 && grid[i-1][j] == 1 && vis[i-1][j] == 0){
            dfsArea++; 
            dfs(grid, vis, i-1, j, dfsArea); 
        }
        if(j-1 >= 0 && grid[i][j-1] == 1 && vis[i][j-1] == 0){
            dfsArea++; 
            dfs(grid, vis, i, j-1, dfsArea); 
        }
        if(i+1 < n && grid[i+1][j] == 1 && vis[i+1][j] == 0){
            dfsArea++; 
            dfs(grid, vis, i+1, j, dfsArea); 
        }
        if(j+1 < m && grid[i][j+1] == 1 && vis[i][j+1] == 0){
            dfsArea++; 
            dfs(grid, vis, i, j+1, dfsArea); 
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m,0)); 
        int area = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int dfsArea = 1;
                    dfs(grid, vis, i, j, dfsArea); 
                    area = max(area, dfsArea); 
                }
            }
        }
        return area; 
    }
};
