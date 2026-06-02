class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        queue<pair<int, int>> q; 
        int fresh = 0; 
        int minutes = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    fresh++; 
                }
                if(grid[i][j] == 2){
                    q.push({i,j}); 
                }
            }
        }

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 

        while(!q.empty() && fresh > 0){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                auto [r,c] = q.front(); 
            q.pop(); 
            for(auto [dr,dc]:dir){
                int nr = r+dr; 
                int nc = c+dc; 
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2; 
                    fresh--; 
                    q.push({nr, nc}); 
                }
                }
            }
            minutes++; 
        }

        if(fresh == 0){
            return minutes; 
        }
        return -1; 
    }
};
