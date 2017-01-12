/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // edge case
        if (root == nullptr) return root;
        
        TreeNode *&l = root->left;
        TreeNode *&r = root->right;
        
        // leaf nodes
        if (l == nullptr && r == nullptr)
            return root;
        
        // reverse subtrees
        TreeNode* tmp = l;
        l = r;
        r = tmp;
        
        // visit subtrees
        this->invertTree(l);
        this->invertTree(r);
        
        // return root's address
        return root;
    }
};
