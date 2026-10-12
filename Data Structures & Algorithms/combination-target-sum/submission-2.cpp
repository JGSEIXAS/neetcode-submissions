class Solution {
private:
    vector<vector<int>> resp;

    void backtrack(vector<int>& nums, int target, vector<int>& caminho, int inicio) {
        if (target < 0) return;
        
        if (target == 0) {
            resp.push_back(caminho);
            return;
        }

        for (int i = inicio; i < nums.size(); i++) {
            caminho.push_back(nums[i]);
            
            backtrack(nums, target - nums[i], caminho, i);
            
            caminho.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> caminho;
        backtrack(nums, target, caminho, 0);
        return resp;
    }
};