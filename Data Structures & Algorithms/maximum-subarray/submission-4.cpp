class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int resp = nums[0];
        int respo = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < resp + nums[i]) cout << nums[i]<< endl;
            resp = max(nums[i], resp + nums[i]);
            respo = max(respo, resp);
        }
        return respo;
    }
};
