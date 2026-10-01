class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> pilha;
        TreeNode* atual = root;

        // O laço roda enquanto tivermos nós para visitar ou caixas guardadas na pilha
        while (atual != nullptr || !pilha.empty()) {
            
            // 1. ESQUERDA: Mergulhamos até o limite esquerdo, guardando o caminho de volta
            while (atual != nullptr) {
                pilha.push(atual);
                atual = atual->left;
            }
            
            // 2. RAIZ: "Voltamos da recursão" (Pegamos a última caixa guardada)
            atual = pilha.top();
            pilha.pop();
            
            // Processamos o nó atual
            k--;
            if (k == 0) {
                return atual->val; // Bingo!
            }
            
            // 3. DIREITA: Agora exploramos o lado direito
            atual = atual->right;
        }

        return -1; // Só por segurança, caso a árvore seja vazia
    }
};