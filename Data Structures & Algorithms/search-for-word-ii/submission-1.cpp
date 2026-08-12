struct TrieNode {
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;

        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isWord = true;
    }
};

class Solution {
public:

    int rows;
    int cols;

    vector<string> result;

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node,
             string& current) {

        // Out of bounds
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        // Already visited
        if(board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        int index = ch - 'a';

        // Current character doesn't exist in Trie
        if(node->children[index] == nullptr) {
            return;
        }

        // Move to Trie child
        node = node->children[index];

        // Add character to current word
        current.push_back(ch);

        // Found a word
        if(node->isWord) {
            result.push_back(current);

            // Avoid duplicate result
            node->isWord = false;
        }

        // Mark cell as visited
        board[r][c] = '#';

        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for(auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;

            dfs(board, nr, nc, node, current);
        }

        // Backtrack
        board[r][c] = ch;
        current.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        rows = board.size();
        cols = board[0].size();

        Trie trie;

        for(string word : words) {
            trie.insert(word);
        }

        string current;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dfs(board, r, c, trie.root, current);
            }
        }

        return result;
    }
};