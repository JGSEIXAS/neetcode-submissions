class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // 1. Jogamos o intervalo novo no final da lista, ignorando a ordem.
        // O push_back é muito mais seguro e rápido que o insert aqui!
        intervals.push_back(newInterval);
        
        // =========================================================
        // 2. A PARTIR DAQUI É O SEU CÓDIGO EXATO DE MERGE INTERVALS
        // =========================================================
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // Ordena pelo início, colocando o novo no lugar certo!
        });
        
        vector<vector<int>> resp;
        vector<int> local = {intervals[0][0], intervals[0][1]};
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= local[1]){
                local[1] = max(local[1], intervals[i][1]); // Funde as colisões
            }
            else{
                resp.push_back(local);
                local = intervals[i];
            }
        }
        resp.push_back(local);
        
        return resp;
    }
};