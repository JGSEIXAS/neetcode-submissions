class Solution {
public:
    string encode(vector<string>& strs) {
        string resultado = "";
        
        for(auto palavra : strs){
            resultado += to_string(palavra.size()) + "#" + palavra;
        }
        
        return resultado;
    }

    vector<string> decode(string s) {
        vector<string> resultado;
        int i = 0;
        
        while(i < s.size()) {
            
            int pos_cerquilha = s.find('#', i);
            
            
            int tamanho = stoi(s.substr(i, pos_cerquilha - i));

            string palavra = s.substr(pos_cerquilha + 1, tamanho);
            resultado.push_back(palavra);
            i = pos_cerquilha + 1 + tamanho;
        }
        
        return resultado;
    }
};