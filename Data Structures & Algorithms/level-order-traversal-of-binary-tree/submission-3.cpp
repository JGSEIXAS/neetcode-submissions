/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resposta;
        if(root == nullptr) return resposta;
        queue<TreeNode*> fila;
        fila.push(root);
        while(!fila.empty()){
            vector<int> andar;
            int tamanho = fila.size();
            for(int i =0; i < tamanho; i++){
                auto atual = fila.front();
                fila.pop();
                andar.push_back(atual->val);
                if(atual->left != nullptr) fila.push(atual->left);
                if(atual->right != nullptr) fila.push(atual->right);
            }
            resposta.push_back(andar);
        }
        return resposta;
    }
};
