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
    string res;
    void dfs(TreeNode *root)
    {
        if (root == nullptr) return;
        res += to_string(root->val);
        if (root->left != nullptr || root->right != nullptr)
        {
            this->res += '(';
            this->dfs(root->left);
            this->res += ')';
        }
        if (root->right != nullptr)
        {
            this->res += '(';
            this->dfs(root->right);
            this->res += ')';
        }
    }
public:
    string tree2str(TreeNode* t) {
        this->res.clear();
        this->dfs(t);
        return this->res;
    }
};
