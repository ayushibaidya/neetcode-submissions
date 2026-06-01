class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        if(n == 0) return; 
        int m = board[0].size(); 

        queue<pair<int, int>> q; 

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0}); 
            }if(board[i][m-1] == 'O'){
                q.push({i, m-1}); 
            }
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                q.push({0, i}); 
            }if(board[n-1][i] == 'O'){
                q.push({n-1, i}); 
            }
        }

        vector<pair<int, int>> directions = {{0, -1}, {1,0}, {-1, 0}, {0,1}}; 

        while(!q.empty()){
            auto [r,c] = q.front(); 
            q.pop(); 
            if(board[r][c] != 'O') continue;

            board[r][c] = 'T';  

            for(auto [dr, dc]:directions){
                int nr = r+dr; 
                int nc = c+dc; 
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O'){
                    q.push({nr,nc}); 
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
        return; 
    }
};
