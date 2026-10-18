class WordDictionary {
private:
    // A mesma estrutura exata da nossa Trie anterior
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;

    // A função detetive recursiva
    bool dfs(string& word, int indice, TrieNode* no) {
        // 1. Base da recursão: chegamos no final da palavra!
        // O caminho que fizemos realmente forma uma palavra válida?
        if (indice == word.size()) {
            return no->isEndOfWord;
        }
        
        char letra = word[indice];
        
        // 2. É o coringa? Temos que tentar todas as 26 portas!
        if (letra == '.') {
            for (int i = 0; i < 26; i++) {
                // Se a porta existe, entramos e mandamos o detetive olhar a próxima letra
                if (no->children[i] != nullptr) {
                    if (dfs(word, indice + 1, no->children[i])) {
                        return true; // Um dos caminhos deu certo!
                    }
                }
            }
            return false; // Tentou todas as portas e nenhuma formou a palavra
        } 
        // 3. É uma letra normal? Caminho reto.
        else {
            int pos = letra - 'a';
            if (no->children[pos] == nullptr) {
                return false; // Porta fechada
            }
            // Entra na porta e continua a busca
            return dfs(word, indice + 1, no->children[pos]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Inserção idêntica à Prefix Tree que fizemos
    void addWord(string word) {
        TrieNode* atual = root;
        for (char letra : word) {
            int pos = letra - 'a';
            if (atual->children[pos] == nullptr) {
                atual->children[pos] = new TrieNode();
            }
            atual = atual->children[pos];
        }
        atual->isEndOfWord = true;
    }
    
    // Dispara a busca usando o detetive a partir do índice 0 e da raiz
    bool search(string word) {
        return dfs(word, 0, root);
    }
};