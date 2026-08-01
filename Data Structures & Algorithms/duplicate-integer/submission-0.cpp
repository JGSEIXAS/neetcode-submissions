class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> visitados;
        int t = nums.size();

        while(t--){
            if(visitados.count(nums[t])) return true;
            visitados.insert(nums[t]);
        }
        return false; 
    }
};