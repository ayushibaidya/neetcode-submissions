class Solution {
public:

    void dfsIsland(vector<vector<int>> &grid, int i, int j){
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 

        for(auto [r,c]:dir){
            int nr = r+i; 
            int nc = c+j; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] > grid[i][j]+1){
                grid[nr][nc] = grid[i][j]+1; 
                dfsIsland(grid, nr, nc); 
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    dfsIsland(grid, i, j); 
                }
            }
        }
    }
};
