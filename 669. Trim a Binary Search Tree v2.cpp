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
    // should also include memory freeing code
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return nullptr;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        int value = root->val;
        if (value < L) return root->right;
        else if (R < value) return root->left;
        else return root;
    }
};
