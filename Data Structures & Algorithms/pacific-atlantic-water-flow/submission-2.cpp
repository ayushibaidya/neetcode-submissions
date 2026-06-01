class Solution {
public:

    void traverse(vector<vector<int>> &heights, queue<pair<int, int>> &ocean, vector<vector<int>> &vis){
        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
        int n = heights.size(); 
        int m = heights[0].size();

        while(!ocean.empty()){
                auto [r,c] = ocean.front();
                ocean.pop(); 
                for(auto& [dr,dc]:dir){
                    int nr = r+dr;
                    int nc = c+dc; 
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                        vis[nr][nc] = 1; 
                        ocean.push({nr, nc}); 
                    }
            }  
        }
        return; 
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size(); 

        vector<vector<int>> visPacific(n, vector<int>(m,0)); 
        vector<vector<int>> visAtlantic(n, vector<int>(m,0)); 


        //pacific - push already accessible row, col 
        queue<pair<int, int>> pacific; 
        for(int j = 0; j < m; j++){
            pacific.push({0,j}); 
            visPacific[0][j] = 1; 
        }
        for(int i = 1; i < n; i++){
            pacific.push({i,0}); 
            visPacific[i][0] = 1; 
        }
        //atlantic - push already accessible row, col 
        queue<pair<int, int>> atlantic; 
        for(int j = 0; j < m; j++){
            atlantic.push({n-1,j}); 
            visAtlantic[n-1][j] = 1;
        }
        for(int i = 0; i < n; i++){
            atlantic.push({i,m-1}); 
            visAtlantic[i][m-1] = 1;
        }

        traverse(heights, pacific, visPacific); 
        traverse(heights, atlantic, visAtlantic);

        vector<vector<int>> results; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visPacific[i][j] == 1 && visAtlantic[i][j] == 1){
                    results.push_back({i,j}); 
                }
            }
        }
        return results; 
    }
};
