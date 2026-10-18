class Solution {
private:
    // A nossa TrieNode "Tunada"
    struct TrieNode {
        TrieNode* children[26];
        string word; // Em vez de bool, guardamos a palavra inteira!
        
        TrieNode() {
            word = ""; // Se for vazio, não é fim de palavra
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    vector<string> resp;

    // A DFS com Backtracking que viaja pelo Tabuleiro E pela Trie ao mesmo tempo
    void dfs(vector<vector<char>>& board, int linha, int coluna, TrieNode* no) {
        // 1. Base de falha do tabuleiro: limites ou célula já visitada
        if (linha < 0 || linha >= board.size() || 
            coluna < 0 || coluna >= board[0].size() || 
            board[linha][coluna] == '#') {
            return;
        }
        
        char letra = board[linha][coluna];
        int indice = letra - 'a';
        
        // 2. A MÁGICA DA PODA (Pruning): Se a letra não tem porta na Trie, pare!
        if (no->children[indice] == nullptr) {
            return;
        }
        
        // 3. Andamos um passo na Trie
        TrieNode* proximoNo = no->children[indice];
        
        // 4. Achou alguma palavra?
        if (proximoNo->word != "") {
            resp.push_back(proximoNo->word);
            proximoNo->word = ""; // Apagamos da Trie para não pegar palavras duplicadas!
        }
        
        // 5. Backtracking no Tabuleiro (A mesma lógica do Word Search I)
        board[linha][coluna] = '#'; // Marca visitado
        
        // Explora as 4 direções mandando o nó ATUALIZADO da Trie
        dfs(board, linha + 1, coluna, proximoNo); // Baixo
        dfs(board, linha - 1, coluna, proximoNo); // Cima
        dfs(board, linha, coluna + 1, proximoNo); // Direita
        dfs(board, linha, coluna - 1, proximoNo); // Esquerda
        
        board[linha][coluna] = letra; // Desfaz
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // 1. Inserimos TODAS as palavras na Trie
        for (string w : words) {
            TrieNode* atual = root;
            for (char letra : w) {
                int pos = letra - 'a';
                if (atual->children[pos] == nullptr) {
                    atual->children[pos] = new TrieNode();
                }
                atual = atual->children[pos];
            }
            atual->word = w; // Guardamos a palavra inteira no final do caminho
        }
        
        // 2. Soltamos o detetive de cada célula do tabuleiro
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        
        return resp;
    }
};