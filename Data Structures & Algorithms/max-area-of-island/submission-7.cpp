class Solution {
public:
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col){
        int n = grid.size(); 
        int m = grid[0].size(); 

        vis[row][col] = 1; 

        int area = 1; 

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}}; 

        for(auto &[r,c]:dir){
            int nr = row+r; 
            int nc = col+c; 

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                area += bfs(grid, vis, nr, nc); 
            }
        }
        return area; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int> (m,0)); 

        int maxArea = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = bfs(grid, vis, i, j); 
                    maxArea = max(area, maxArea); 
                }
            }
        }
        return maxArea; 
    }
};
