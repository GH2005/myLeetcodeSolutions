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
public:
    bool isValidBST(TreeNode* root, int leftBorder = INT_MIN, int rightBorder = INT_MAX) {
        if (!root) return true;
        int v = root->val;
        if (!(leftBorder <= v && v <= rightBorder)) return false;
        if (v < v - 1 && root->left) return false;
        if (v + 1 < v && root->right) return false;
        if (this->isValidBST(root->left, leftBorder, v - 1)
            && this->isValidBST(root->right, v + 1, rightBorder))
            return true;
        else return false;
    }
};
