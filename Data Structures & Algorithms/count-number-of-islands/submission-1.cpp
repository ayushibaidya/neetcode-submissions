class Solution {
public:

    void dfsIslands(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j){
        int n = grid.size(); 
        int m = grid[0].size(); 

        vis[i][j] = 1; 

        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0,1}}; 

        for(auto [r, c]:directions){
            int nr = i + r; 
            int nc = j + c; 
            if(nr < n && nc < m && nr >= 0 && nc >= 0 && grid[nr][nc] == '1' && vis[nr][nc] == 0){
                dfsIslands(grid, vis, nr, nc); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        int islands = 0; 

        vector<vector<int>> vis(n, vector<int> (m, 0)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfsIslands(grid, vis, i, j); 
                    islands++; 
                }
            }
        }
        return islands; 
    }
};
