class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // o indice do comeco da lista ligara o restante
        unordered_map<int,int> mapa;
        vector<int> ordem;
        int resultado =0;
        for(auto a: nums){
            mapa[a]++;
        }
        for(int i =0; i < nums.size(); i++){
            if(!mapa[nums[i]-1]){
                ordem.push_back(nums[i]);
            }
        }
        for(auto valor : ordem){
            int cont =1;
            while(true){
                if(mapa[valor+1]){
                    cont++;
                    valor++;
                }
                else break;
            }
            resultado = max(resultado, cont);
        }
        
        return resultado;
    }
};
