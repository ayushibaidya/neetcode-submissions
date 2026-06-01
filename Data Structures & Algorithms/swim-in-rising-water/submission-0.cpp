class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq; 

        //dist source initial - 0, starting index (0,0)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 
        vector<vector<int>> vis(n, vector<int>(m,0)); 
        dist[0][0] = grid[0][0]; 

        //val = grid[dr][dc]
        //grid[dr][dc], {dr, dc}
        pq.push({grid[0][0], {0,0}}); 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 

        while(!pq.empty()){
            auto [time,cell] = pq.top(); 
            pq.pop(); 

            int r = cell.first; 
            int c = cell.second; 

            //if we reached the last grid[n-1][m-1]
            if(r == n-1 && c == m-1) return time;

            if(vis[r][c]) continue; 
            vis[r][c] = 1; 
            
            for(auto [dr, dc]:dir){
                int nr = r + dr; 
                int nc = c + dc; 

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0){
                    int newTime = max(time, grid[nr][nc]); 
                    //some condition goes here to store the max val in curr path
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime; 
                        pq.push({newTime, {nr, nc}}); 
                    }
                }
            }
        }
        return -1; 
    }
};
