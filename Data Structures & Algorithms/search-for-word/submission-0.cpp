class Solution {
public:

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int wordIndex){
        if(wordIndex == word.size()){
            return true; 
        }
        int n = board.size(); 
        int m = board[0].size();

        //boundary mismatch
        if(i < 0 || j < 0 || i >=n || j >=m || board[i][j] != word[wordIndex]){
            return false;
        }

        char temp = board[i][j]; 
        board[i][j] = '#'; //mark visited

        bool found = dfs(board, word, i+1, j, wordIndex+1) || dfs(board, word, i-1, j, wordIndex+1) || dfs(board, word, i, j+1, wordIndex+1) || dfs(board, word, i, j-1, wordIndex+1); 
        
        board[i][j] = temp; 

        return found; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 

        int wordIndex = 0; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board, word, i, j, 0)){
                    return true; 
                }
            }
        }
        return false; 
    }
};
