class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](auto a, auto b){
            return a[0] < b[0];
        });
        vector<vector<int>> resp;
        vector<int> local= {intervals[0][0], intervals[0][1]};
        for(int i = 1 ; i< intervals.size(); i++){
            if(intervals[i][0] <= local[1]){
                local = {local[0], max(local[1],intervals[i][1])};
            }
            else{
                resp.push_back(local);
                local = {intervals[i][0], intervals[i][1]};
            }
        }
        resp.push_back(local);
        return resp;
    }
};
