class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int inicio = 1;
        int horas = h;
        int max = *max_element(piles.begin(), piles.end());
        while(inicio < max){
            int meio = inicio + (max - inicio)/2;
            cout<<inicio<< " "<< meio<<endl;
            long long cont = 0;
            for(auto valor : piles){
                cont += (valor + meio -1)/meio;
            }
            if(cont <= horas){
                max = meio;
            }
            else{
                inicio = meio +1;
            }
        }
        
        return max;
    }
};
