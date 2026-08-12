class Solution {
public:

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int row, int col, int i, string &word, vector<pair<int, int>> &path){

        int n = board.size(); 
        int m = board[0].size();

        if(row < 0 || row >= n || col < 0 || col >= m){
            return false; 
        } 

        if(vis[row][col]){
            return false; 
        }

        if(board[row][col] != word[i]){
            return false; 
        }

        if(i == word.length()-1){
            path.push_back({row, col}); 
            return true; 
        }

        vis[row][col] = true; 
        path.push_back({row, col}); 

        vector<pair<int, int>> dir = {{-1, 0}, {0,1}, {1, 0}, {0, -1}}; 

        for(auto [r,c]: dir){
            int nr = r + row; 
            int nc = c + col; 

            if(dfs(board, vis, nr, nc, i+1, word, path)){
                return true; 
            }
        }
        
        vis[row][col] = false; 
        path.pop_back(); 

        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 

        vector<vector<bool>> vis(n, vector<bool> (m, false)); 
        vector<pair<int, int>> path; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, vis, i, j, 0, word, path)){
                        return true; 
                    }
                    path.clear(); 
                }
            }
        }
        return false; 
    }
};
