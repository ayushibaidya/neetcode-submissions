class Solution {
public:

    void traverseIsland(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1; 
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}}; 
        for(auto &[r,c]:dir){
            int nr = i+r; 
            int nc = j+c; 
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && vis[nr][nc] == 0){
                traverseIsland(grid, nr, nc, vis); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int> (m, 0)); 

        int islands = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){ 
                    traverseIsland(grid, i, j, vis); 
                    islands++;
                }
            }
        }
        return islands; 
    }
};
