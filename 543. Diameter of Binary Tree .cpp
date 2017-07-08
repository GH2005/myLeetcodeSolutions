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
    int maxDist = 0;
    int dfs(TreeNode *root)
    {// return the maximum depth possible given by this subtree
        int depthLeft = root->left == nullptr ? 0 : this->dfs(root->left);
        int depthRight = root->right == nullptr ? 0 : this->dfs(root->right);
        this->maxDist = max(this->maxDist, depthLeft + depthRight);
        return max(depthLeft, depthRight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->maxDist = 0;
        if (root != nullptr) this->dfs(root);
        return this->maxDist;
    }
};
