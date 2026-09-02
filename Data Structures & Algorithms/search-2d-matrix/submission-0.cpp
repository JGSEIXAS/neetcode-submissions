class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int linhas = matrix.size();
        int colunas = matrix[0].size();
        
        int esquerda = 0;
        int direita = (linhas * colunas) - 1;
        
        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            
            int linha_real = meio / colunas;
            int coluna_real = meio % colunas;
            
            int valor_meio = matrix[linha_real][coluna_real];
            
            if (valor_meio == target) return true;
            else if (valor_meio < target) esquerda = meio + 1;
            else direita = meio - 1;
        }
        
        return false;
    }
};