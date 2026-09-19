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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q == nullptr and p== nullptr) return true;
        if((p == nullptr and q!= nullptr) ||(q == nullptr and p!= nullptr) ||p-> val != q-> val) return false;
        else{
            if(isSameTree(p->left, q->left) == false) return false;
            if(!isSameTree(p->right, q->right))return false;
        } 
        return true;
    }
};
