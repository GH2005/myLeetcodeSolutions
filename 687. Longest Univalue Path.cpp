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
    int maxLen = 0;
    int dfs(TreeNode *root)
    {
        int value = root->val;
        int lenL = 0;
        int lenR = 0;
        TreeNode *l = root->left, *r = root->right;
        if (l != nullptr)
            if (l->val == value) lenL = 1 + dfs(l);
            else dfs(l);
        if (r != nullptr)
            if (r->val == value) lenR = 1 + dfs(r);
            else dfs(r);
        this->maxLen = max(this->maxLen, lenL + lenR);
        return max(lenL, lenR);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        this->maxLen = 0;
        if (root != nullptr) this->dfs(root);
        return this->maxLen;
    }
};
