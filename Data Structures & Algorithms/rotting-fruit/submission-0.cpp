class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int minutes = 0; int fresh = 0; 

        queue<pair<int, int>> q; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j}); 
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }


        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1,0}, {0,-1}}; 
   
        while(!q.empty() && fresh > 0){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                auto [r,c] = q.front(); 
                q.pop(); 
                for(auto [dr,dc]:directions){
                    int nr = r+dr; 
                    int nc = c+dc; 

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2; 
                        fresh--; 
                        q.push({nr,nc}); 
                    }
                }
            }
            minutes++; 
        }
        return (fresh == 0) ? minutes:-1; 
    }
};
