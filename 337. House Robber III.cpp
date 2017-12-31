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
    /* max gain from the subtree (i.e., dp value) */
    pair<int, int> dfs(TreeNode *root)
    {   // first value --- max gain including root
        // second value --- max gain excluding root
        pair<int, int> leftDp, rightDp;
        if (root->left != nullptr) leftDp = dfs(root->left);
        if (root->right != nullptr) rightDp = dfs(root->right);
        pair<int, int> retDp;
        retDp.first = root->val + leftDp.second + rightDp.second;
        retDp.second = max(leftDp.first, leftDp.second) + max(rightDp.first, rightDp.second);
        return retDp;
    }
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        pair<int, int> retPair = dfs(root);
        return max(retPair.first, retPair.second);
    }
};
