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
    bool isValidBST(TreeNode* root) {
        return validar(root, INT_MIN, INT_MAX);
    }
    bool validar(TreeNode* root, long long piso, long long teto){
        bool resp = true;
        if(root == nullptr)return resp;
        if(root->val >= teto or root->val <= piso) resp = false;
        else{
            resp = validar(root->right, root -> val, teto) and validar(root->left, piso, root->val);
        }
        return resp;
    }
};
