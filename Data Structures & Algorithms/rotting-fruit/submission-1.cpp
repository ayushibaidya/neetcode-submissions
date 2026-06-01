class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int fruits = 0;  

        int n = grid.size(); 
        int m = grid[0].size(); 

        queue<pair<int, int>> q; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }if(grid[i][j] == 1){
                    fruits++; 
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0 ,1}, {-1, 0}, {0, -1}}; 

        while(!q.empty() && fruits > 0){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                auto [r,c] = q.front(); 
                q.pop(); 

                for(auto [dr,dc]:dir){
                    int nr = dr+r; 
                    int nc = dc+c; 
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2; 
                        fruits--; 
                        q.push({nr, nc});
                    }
                }
            }
            minutes++; 
        } 
        return (fruits == 0) ? minutes : -1;
    }
};
