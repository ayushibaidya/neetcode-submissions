class Solution {
public:

    bool backTrack(vector<vector<char>> &board, string word, int index, int i, int j){
        int n = board.size(); 
        int m = board[0].size();  

        char letter = board[i][j]; 
        board[i][j] = '#'; 

        if(index == word.size()-1){
            board[i][j] = letter;
            return true; 
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 

        for(auto [r,c]:directions){
            int nr = r+i; 
            int nc = c+j; 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] == word[index+1]){
                if(backTrack(board, word, index+1, nr, nc)){
                    board[i][j] = letter;
                    return true; 
                }
            }
        }
        board[i][j] = letter; 
        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 

        int index = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[index]){
                    if(backTrack(board, word, index, i, j)){
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
};
