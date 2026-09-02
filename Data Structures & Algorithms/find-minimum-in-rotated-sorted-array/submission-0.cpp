class Solution {
public:
    int findMin(vector<int> &nums) {
        auto resp = min_element(nums.begin(), nums.end());
        return *resp;
    }
};
