class Solution {
public:

    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col){
        int n = grid.size(); 
        int m = grid[0].size(); 

        vis[row][col] = 1; 

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 

        for(auto& [r,c]:dir){
            int nr = row+r; 
            int nc = col+c; 
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && vis[nr][nc] == 0){
                bfs(grid,vis, nr, nc); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int> (m,0)); 

        int count = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(grid, vis, i, j); 
                    count++; 
                }
            }
        }
        return count; 
    }
};
