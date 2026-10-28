class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = true;
        int pulos = nums[0];
        for(int i = 0; i< nums.size() - 1; i++){
            if(pulos < nums[i]){
                pulos = nums[i];
            }
            pulos--;
            cout<< pulos<< endl;
            if(pulos < 0){
                res = false;
                break;
            } 
        }
        return res;
    }
};
