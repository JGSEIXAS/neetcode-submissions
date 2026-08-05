class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int valor=1;
        vector<int> resultado;
        int zero= count(nums.begin(),nums.end(),0);
        if(zero>=2){
            for(int i =0; i < nums.size();i++){
                resultado.push_back(0);
            }
        }
        else if(zero == 1){
            for(int &num : nums){
                if(num!=0) valor*=num;
            }
            for(int i =0; i < nums.size();i++){
                if(nums[i]== 0) resultado.push_back(valor);
                else resultado.push_back(0);
            }
        }
        else{
            for(int &num : nums){
                valor*=num;
            }
            for(int i =0; i < nums.size();i++){
                int a = valor;
                a/=nums[i];
                resultado.push_back(a);
            }
        }
        return resultado;
    }
};
