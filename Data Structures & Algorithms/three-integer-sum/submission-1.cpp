class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resultado;
 
        for(int k = 1; k< nums.size(); k++){
            int i =0;
            int j = nums.size() - 1;
            int target = nums[k] * -1;
            while(i< k and j> k){
                if(nums[i] + nums[j] < target){
                    i++;
                }
                else if(nums[i] + nums[j] > target){
                    j--;
                }
                else if(nums[i] + nums[j] == target){
                    resultado.insert({nums[i], nums[k], nums[j]});
                    i++;
                    j--;
                }
            }
        }
            vector<vector<int>> resultados(resultado.begin(), resultado.end());
            return resultados;
    }
};
