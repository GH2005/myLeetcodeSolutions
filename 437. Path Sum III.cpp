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
    int count = 0;
    void dfs(TreeNode *root, int rem)
    {
        rem -= root->val;
        if (rem == 0) this->count ++;
        if (root->left != nullptr) this->dfs(root->left, rem);
        if (root->right != nullptr) this->dfs(root->right, rem);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        this->count = 0;
        stack<TreeNode *> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            this->dfs(node, sum);
            if (node->left != nullptr) stk.push(node->left);
            if (node->right != nullptr) stk.push(node->right);
        }
        return this->count;
    }
};
