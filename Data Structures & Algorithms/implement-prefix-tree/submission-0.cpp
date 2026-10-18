class PrefixTree {
private:
    // 1. Criamos o molde do nosso Nó aqui dentro da classe
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
    
    // 2. Declaramos a nossa raiz
    TrieNode* root;

public:
    // Construtor: O que acontece quando o LeetCode chama "new PrefixTree()"
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* atual = root;
        
        for (char letra : word) {
            int indice = letra - 'a'; // Traduz 'a'->0, 'b'->1, 'z'->25
            
            // Se o caminho não existe, nós criamos a porta
            if (atual->children[indice] == nullptr) {
                atual->children[indice] = new TrieNode();
            }
            // Entramos na porta
            atual = atual->children[indice];
        }
        
        // Fim da palavra, levantamos a bandeira
        atual->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* atual = root;
        
        for (char letra : word) {
            int indice = letra - 'a';
            
            // Se a porta está fechada (nullptr), a palavra não existe
            if (atual->children[indice] == nullptr) {
                return false;
            }
            atual = atual->children[indice];
        }
        
        // Retornamos true APENAS se for o fim de uma palavra real
        return atual->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* atual = root;
        
        for (char letra : prefix) {
            int indice = letra - 'a';
            
            // Se o caminho quebrar no meio, o prefixo não existe
            if (atual->children[indice] == nullptr) {
                return false;
            }
            atual = atual->children[indice];
        }
        
        // Se chegamos até aqui sem bater em nullptr, o caminho existe!
        return true;
    }
};