class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int, greater<int>> dict;
        for(auto num : nums){
            dict[num]++;
        }
        vector<pair<int,int>> aux(dict.size());
        int cont = 0;
        for(auto const& [key, value] : dict){
            aux[cont].first = value;
            aux[cont].second = key;
            cont++;
        } 

        vector<int> resultado;

        sort(aux.rbegin(), aux.rend());
        for(auto x: aux){
            if(k>0){
                resultado.push_back(x.second);
                k--;
            }
        }

        return resultado;
    }
};
