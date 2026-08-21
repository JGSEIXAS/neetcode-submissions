class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mapa;
        int resp = 0;
        int resultado =0;
        int i =0;

            for(int j = 0; j< s.size();j++){
                if(!mapa[s[j]]){
                    mapa[s[j]]++;
                    resp++;
                    resultado = max(resp, resultado);
                } 
                else{
                    while(s[i]!= s[j]){
                        mapa.erase(s[i]);
                        i++;
                        resp--;
                    }
                    mapa.erase(s[i]);
                    i++;
                    resp--;
                    mapa[s[j]]++;
                    resp++;
                    resultado = max(resp, resultado);
                }
            }
        
        return resultado;
    }
};
