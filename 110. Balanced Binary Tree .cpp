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
    bool balanced = true;
    int dfs(TreeNode *root)
    {
        if (!this->balanced) return 0;
        int hLeft = root->left == nullptr ? 0 : this->dfs(root->left);
        int hRight = root->right == nullptr ? 0 : this->dfs(root->right);
        if (abs(hLeft-hRight) > 1) this->balanced = false;
        return max(hLeft, hRight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        this->balanced = true;
        if (root == nullptr) return this->balanced;
        int height = this->dfs(root);
        return this->balanced;
    }
};
