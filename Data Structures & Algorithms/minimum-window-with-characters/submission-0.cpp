class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapa;
        for (char letra : t) {
            mapa[letra]++;
        }
        
        int esquerda = 0, cont = 0;
        int min_tamanho = INT_MAX;
        int inicio_minimo = 0;
        
        for (int j = 0; j < s.size(); j++) {
            if (mapa[s[j]] > 0) {
                cont++;
            }
            mapa[s[j]]--;
            
            while (cont == t.size()) {
                    if (j - esquerda + 1 < min_tamanho) {
                    min_tamanho = j - esquerda + 1;
                    inicio_minimo = esquerda;
                }
                
                mapa[s[esquerda]]++;
                
                if (mapa[s[esquerda]] > 0) {
                    cont--; 
                }
                esquerda++;
            }
        }
        
        return min_tamanho == INT_MAX ? "" : s.substr(inicio_minimo, min_tamanho);
    }
};