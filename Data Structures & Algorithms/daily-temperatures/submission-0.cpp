class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pair<int,int>> menor;
        vector <int> resposta(temperatures.size());
        for(int i =0; i< temperatures.size(); i++){
            if(menor.empty()) menor.push({temperatures[i], i});
            else if(!menor.empty()&& temperatures[i]<=menor.top().first) menor.push({temperatures[i],i});
            else{
                while(!menor.empty() && temperatures[i]> menor.top().first){
                    resposta[menor.top().second]=(abs(menor.top().second - i));
                    menor.pop();
                }
                menor.push({temperatures[i], i});
            }
        }
        return resposta;
    }
};
