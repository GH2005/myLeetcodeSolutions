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
    int lastVal;
    int minDiffSofar;
    void inorder(TreeNode *root)
    {
        if (root == nullptr) return;
        this->inorder(root->left);
        if (this->lastVal != -1)
            this->minDiffSofar = min(this->minDiffSofar, root->val - this->lastVal);
        this->lastVal = root->val;
        this->inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        this->lastVal = -1;
        this->minDiffSofar = INT_MAX;
        this->inorder(root);
        return this->minDiffSofar;
    }
};
