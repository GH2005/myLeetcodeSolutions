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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        sum -= root->val;
        if (root->left != nullptr && this->hasPathSum(root->left, sum))
            return true;
        if (root->right != nullptr && this->hasPathSum(root->right, sum))
            return true;
        if (root->right == root->left && sum == 0) return true;
        return false;
    }
};
