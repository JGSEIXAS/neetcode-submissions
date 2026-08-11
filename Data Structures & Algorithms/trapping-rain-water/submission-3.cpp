class Solution {
public:
    int trap(vector<int>& height) {
    vector<int> parede_e;
    vector<int> parede_d;

    int aux = 0;
    for(auto valor : height){
        aux = max(aux, valor);
        parede_e.push_back(aux);
    }

    aux = 0;
    for(int i = height.size()-1; i>=0; i--){
        aux = max(aux, height[i]);
        parede_d.push_back(aux);
    }
    reverse(parede_d.begin(),parede_d.end());
    int resultado = 0;


    for(int i =0; i< height.size(); i++){
        resultado += min(parede_e[i], parede_d[i]) - height[i];
    }

    
    return resultado;
    }
};
