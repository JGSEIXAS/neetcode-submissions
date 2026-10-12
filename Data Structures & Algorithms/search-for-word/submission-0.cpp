class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int linha, int coluna, int indice) {
        
        if (indice == word.size()) {
            return true;
        }
        
        if (linha < 0 || linha >= board.size() || 
            coluna < 0 || coluna >= board[0].size() || 
            board[linha][coluna] != word[indice]) {
            return false;
        }
        
        char letra_original = board[linha][coluna];
        board[linha][coluna] = '#';
        
        bool achou = dfs(board, word, linha + 1, coluna, indice + 1) || 
                     dfs(board, word, linha - 1, coluna, indice + 1) ||
                     dfs(board, word, linha, coluna + 1, indice + 1) || 
                     dfs(board, word, linha, coluna - 1, indice + 1);

        board[linha][coluna] = letra_original;
        
        return achou;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int linhas = board.size();
        int colunas = board[0].size();
        
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true; 
                    }
                }
                
            }
        }
        return false;
    }
};