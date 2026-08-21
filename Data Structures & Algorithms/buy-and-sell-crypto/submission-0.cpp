class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resp=0;
        for(int i = 0; i< prices.size();i++){
            for(int j =i; j< prices.size();j++){
                if(prices[j]> prices[i]){
                    resp = max(resp, prices[j]-prices[i]);
                }
            }
        }
        return resp;
    }
};
