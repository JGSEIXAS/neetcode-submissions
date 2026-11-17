class Solution {
public:

    void afundar(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j< 0 || j >= grid[0].size() || i>= grid.size()) return;
        if(grid[i][j]=='1') grid[i][j] = '0';
        else return;
        afundar(grid, i + 1, j);
        afundar(grid, i, j - 1);
        afundar(grid, i, j + 1);
        afundar(grid, i - 1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ilhas = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){ 
                    ilhas++;
                    afundar(grid, i, j);
                }
            }
        }
        return ilhas;
    }
};
