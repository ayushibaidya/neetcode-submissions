class Solution {
public:

    int countArea(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1; 
        int n = grid.size(); 
        int m = grid[0].size(); 

        int area = 1; 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 

        for(auto &[r,c]:dir){
            int nr = r+i; 
            int nc = c+j; 

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                area += countArea(grid, nr, nc, vis); 
            }
        }
        return area; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m,0)); 

        int maxArea = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int area = countArea(grid, i, j, vis); 
                    maxArea = max(maxArea, area); 
                }
            }
        }
        return maxArea; 
    }
};
