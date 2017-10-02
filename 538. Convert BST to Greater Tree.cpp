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
    int dfs(TreeNode *root, int sumOfUpperGreaters)
    {
        int originalVal = root->val;
        int rightSum = root->right == nullptr ? 0 : dfs(root->right, sumOfUpperGreaters);
        root->val = originalVal + rightSum + sumOfUpperGreaters;
        int leftSum = root->left == nullptr ? 0 : dfs(root->left, root->val);
        return leftSum + originalVal + rightSum;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        this->dfs(root, 0);
        return root;
    }
};
