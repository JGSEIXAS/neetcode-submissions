class Solution {
   public:
    int characterReplacement(string s, int k) {
        int resultado = 0;
        int esquerda = 0;
        unordered_map <char,int> mapa;
            int resp = 0;
        for (int j = esquerda; j < s.size(); j++) {
            mapa[s[j]]++;
            pair<char,int> maior{'0',0};
            for(auto valor: mapa){
                if(valor.second > maior.second){
                    maior = valor;
                }
            }
            if(j - esquerda + 1 - maior.second > k){
                mapa[s[esquerda]]-=1;
                esquerda++;
                resp --;
            }
            resp++;
            resultado = max(resultado, resp);
        }
        return resultado;
    }
};
