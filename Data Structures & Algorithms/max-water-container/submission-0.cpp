class Solution {
public:
    int maxArea(vector<int>& heights) {
        int esquerda = 0;
        int direita = heights.size()- 1;
        int resultado = 0;
        while(esquerda < direita){
            int conta = min(heights[esquerda], heights[direita]) * (direita - esquerda);
            if(conta > resultado) resultado = conta;
            else if(heights[esquerda] < heights[direita]) esquerda++;
            else direita --;
        }
        return resultado;
    }
};
