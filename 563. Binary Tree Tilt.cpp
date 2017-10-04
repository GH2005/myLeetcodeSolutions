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
    int sumOfTilts = 0;
    int dfs(TreeNode *root)
    {// returns sum of all nodes in this subtree
        int leftSum = root->left == nullptr ? 0 : dfs(root->left);
        int rightSum = root->right == nullptr ? 0 : dfs(root->right);
        this->sumOfTilts += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        sumOfTilts = 0;
        if (root == nullptr) return sumOfTilts;
        this->dfs(root);
        return sumOfTilts;
    }
};
