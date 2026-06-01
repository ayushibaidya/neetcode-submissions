class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<pair<int, int>> dir = {{1, 0}, {-1,0}, {0, -1}, {0, 1}}; 

        int maxArea = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int area = 0; 
                    queue<pair<int, int>> q; 
                    q.push({i, j}); 
                    grid[i][j] = 0; 
                    while(!q.empty()){
                        auto [r,c] = q.front(); 
                        q.pop(); 
                        area++; 
                        for(auto [dr, dc]:dir){
                            int nr = r + dr; 
                            int nc = c + dc; 
                            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                                q.push({nr, nc}); 
                                grid[nr][nc] = 0;
                            }
                        }
                    }
                    maxArea = max(maxArea, area); 
                }
            }
        }
        return maxArea; 
    }
};
