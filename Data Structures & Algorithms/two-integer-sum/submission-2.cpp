class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> resultado;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j< nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    resultado.push_back(i);
                    resultado.push_back(j);
                    return resultado;
                }
            }
        }
    }
};
