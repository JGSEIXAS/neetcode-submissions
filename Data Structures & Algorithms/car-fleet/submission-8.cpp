class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> carro;
        stack<pair<double,double>> jafoi;
        int resultado =0;
        for(int i =0; i< position.size(); i++){
            carro.push_back({position[i],speed[i]});
        }
        sort(carro.rbegin(),carro.rend());
        for(int i = 0; i< carro.size();i++){
            if(!jafoi.empty() && ((target - jafoi.top().first)/jafoi.top().second) >= ((target - carro[i].first) / carro[i].second)){
                continue;
            }
            else{
                resultado++;
                jafoi.push(carro[i]);
            }
        }
        return jafoi.size();
    }
};
