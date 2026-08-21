class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> numeros; 
        int resposta = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int valor = heights[i];
            int indice_inicio = i; 
            
            while(!numeros.empty() && valor < numeros.top().first) {
                pair<int, int> pilha = numeros.top();
                numeros.pop();
                
                resposta = max(resposta, pilha.first * (i - pilha.second));
                
                indice_inicio = pilha.second;
            }
            
            numeros.push({valor, indice_inicio});
        }
        while(!numeros.empty()) {
            pair<int, int> pilha = numeros.top();
            numeros.pop();
            
            int largura = heights.size() - pilha.second;
            resposta = max(resposta, pilha.first * largura);
        }
        
        return resposta;
    }
};