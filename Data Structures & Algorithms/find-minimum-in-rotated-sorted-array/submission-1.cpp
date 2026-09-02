class Solution {
public:
    int findMin(vector<int> &nums) {
        int mn = INT_MAX;
        for(int i : nums) {
            mn = min(i , mn);
        }
        return mn;
    }
};
