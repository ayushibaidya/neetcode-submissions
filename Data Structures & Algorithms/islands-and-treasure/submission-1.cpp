class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
        queue<pair<int, int>> q; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j}); 
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front(); 
            q.pop(); 
            for(auto [dr, dc]:dir){
                int nr = dr+r; 
                int nc = dc+c; 
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 2147483647){
                    grid[nr][nc] = grid[r][c] + 1; 
                    q.push({nr, nc}); 
                }
            }
        }
    }
};
