class Solution {
public:

    void traverse(vector<vector<char>> &board, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1; 

        int n = board.size(); 
        int m = board[0].size(); 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
        for(auto& [r,c]:dir){
            int nr = r+i; 
            int nc = c+j; 
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O'){
                traverse(board, nr, nc, vis); 
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        //top row and bottom row 
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                traverse(board, 0, j, vis); 
            }
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
               traverse(board, n-1, j, vis); 
            }
        }
        //left col and right col 
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                traverse(board, i, 0, vis);  
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                traverse(board, i, m-1, vis);  
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X'; 
                }
            }
        }
        return; 
    }
};
