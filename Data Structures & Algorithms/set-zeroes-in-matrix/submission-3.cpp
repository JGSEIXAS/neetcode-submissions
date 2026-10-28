class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> linhas;
        map<int,int> colunas;

        for(int i = 0; i < matrix.size(); i++){
            for(int  j= 0; j< matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    linhas[i]++;
                    colunas[j]++;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int  j= 0; j< matrix[0].size(); j++){
                if(linhas[i] || colunas[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
        
    }
};
