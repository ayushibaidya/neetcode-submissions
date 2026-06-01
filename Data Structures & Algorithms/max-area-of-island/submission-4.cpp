class Solution {
public:

    int dfsIslands(vector<vector<int>> &grid, int i, int j){
        grid[i][j] = 0; 

        int n = grid.size(); 
        int m = grid[0].size(); 

        int area = 1; 

        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 

        for(auto [r,c]:dir){
            int nr = r + i; 
            int nc = c + j; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                area += dfsIslands(grid, nr, nc); 
            }
        }
        return area; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        //dont need vis, mark grid as 0 

        int maxArea = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int area = dfsIslands(grid, i, j); 
                    maxArea = max(maxArea, area); 
                }
            }            
        }
        return maxArea; 
    }
};
