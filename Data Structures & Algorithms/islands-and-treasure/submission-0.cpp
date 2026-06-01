class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        queue<pair<int, int>> q; 

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j}); 
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front(); 
            q.pop(); 

            for(auto [dr,dc]:directions){
                int nr = r+dr; 
                int nc = c+dc; 

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1; 
                    q.push({nr,nc}); 
                }
            }
        }
        return; 
    }
};
