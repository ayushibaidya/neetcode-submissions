class Solution {
public:

    bool findWord(vector<vector<char>>&board, string &word, int index, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1; 

        if(index == word.size()-1) return true;

        int n = board.size(); 
        int m = board[0].size(); 

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}}; 

        for(auto [r,c]:dir){
            int nr = i+r; 
            int nc = j+c; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && board[nr][nc] == word[index+1]){
                if(findWord(board, word, index+1, nr, nc, vis)){
                    return true; 
                }
            } 
        }
        vis[i][j] = 0;
        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 

        int index = 0; 

        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[index]){
                    if(findWord(board, word, index, i, j, vis)){
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
};
