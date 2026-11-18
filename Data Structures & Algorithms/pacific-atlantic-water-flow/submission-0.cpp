class Solution {
    
    void subir(vector<vector<int>>& h, vector<vector<bool>>& vis, int r, int c, int anterior) {
        int R = h.size(), C = h[0].size();

        if (r < 0 || r >= R || c < 0 || c >= C) return;  // fora da grade
        if (vis[r][c]) return;                            // já visitei
        if (h[r][c] < anterior) return;                   // mais baixa: não dá pra subir

        vis[r][c] = true;

        subir(h, vis, r + 1, c, h[r][c]);   // baixo
        subir(h, vis, r - 1, c, h[r][c]);   // cima
        subir(h, vis, r, c + 1, h[r][c]);   // direita
        subir(h, vis, r, c - 1, h[r][c]);   // esquerda
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        vector<vector<bool>> pac(R, vector<bool>(C, false));
        vector<vector<bool>> atl(R, vector<bool>(C, false));

        for (int r = 0; r < R; r++) {
            subir(heights, pac, r, 0, -1);        // borda esquerda -> Pacífico
            subir(heights, atl, r, C - 1, -1);    // borda direita  -> Atlântico
        }
        for (int c = 0; c < C; c++) {
            subir(heights, pac, 0, c, -1);        // borda de cima  -> Pacífico
            subir(heights, atl, R - 1, c, -1);    // borda de baixo -> Atlântico
        }

        vector<vector<int>> resp;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (pac[r][c] && atl[r][c])
                    resp.push_back({r, c});
        return resp;
    }
};