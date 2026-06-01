class Solution {
public:

    int dfsIslands(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j){
        int n = grid.size(); 
        int m = grid[0].size(); 

        vis[i][j] = 1;
        int area = 1; 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(auto [dr,dc]:dir){
            int nr = dr + i; 
            int nc = dc + j; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0){
                area += dfsIslands(grid, vis, nr, nc); 
            }
        }
        return area; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        int maxArea = 0; 

        vector<vector<int>> vis(n, vector<int> (m, 0)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int area = dfsIslands(grid, vis, i, j); 
                    maxArea = max(maxArea, area); 
                }
            }
        }
        return maxArea; 
    }
};
