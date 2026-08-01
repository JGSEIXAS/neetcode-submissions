class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> ordem;
    for(int i=0; i < strs.size(); i++){
        string sorted = strs[i];
        sort(sorted.begin(),sorted.end());
        ordem[sorted].push_back(strs[i]);
    }
    vector<vector<string>> resultado;
    for(auto const& [key, value] : ordem){
        resultado.push_back(value);
    }
    return resultado;
    }
};