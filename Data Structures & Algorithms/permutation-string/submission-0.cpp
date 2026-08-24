class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string menor,maior;
        unordered_map <char, int> mapa;
        if(s1.size()<= s2.size()){
            menor = s1;
            maior = s2;
        } 
        else{
            return false;
        }

        for(auto valor: menor){
            mapa[valor]++;
        }

        int esquerda = 0;
        int tamanho = 0;
        bool flag = false;
        for(int j = esquerda; j< maior.size(); j++){
            mapa[maior[j]]--;
            tamanho++;
            while(mapa[maior[j]]<0){
                mapa[maior[esquerda]] +=1;
                esquerda++;
                tamanho --;
            }
            if(tamanho == menor.size()) return true;
           
        }

        return flag;
    }
};
