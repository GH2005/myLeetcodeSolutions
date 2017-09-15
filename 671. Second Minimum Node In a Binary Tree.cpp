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
    int smallest = INT_MIN;
    int dfs(TreeNode *root)
    {
        int value = root->val;
        if (value > this->smallest) return value;
        if (root->left == nullptr) return INT_MAX;
        return min(this->dfs(root->left), this->dfs(root->right));
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        this->smallest = root->val;
        int res = this->dfs(root);
        if (res == INT_MAX) return -1;
        else return res;
    }
};
