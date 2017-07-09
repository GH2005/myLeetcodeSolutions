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
    string stk;
    vector<string> res;
    void dfs(TreeNode *root)
    {
        int oriSize = this->stk.size();
        if (root->left != nullptr)
        {
            string str = "->" + to_string(root->left->val);
            this->stk += str;
            this->dfs(root->left);
            this->stk.resize(oriSize);
        }
        if (root->right != nullptr)
        {
            string str = "->" + to_string(root->right->val);
            this->stk += str;
            this->dfs(root->right);
            this->stk.resize(oriSize);
        }
        if (root->left == root->right)
            this->res.push_back(this->stk);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        this->res.clear();
        if (root == nullptr) return this->res;
        string str = to_string(root->val);
        int oriSize = this->stk.size();
        this->stk += str;
        this->dfs(root);
        this->stk.resize(oriSize);
        return this->res;
    }
};
