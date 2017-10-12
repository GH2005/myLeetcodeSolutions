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
    TreeNode *trim_left(TreeNode *root)
    {// inorder traversal
        if (root->left != nullptr)
            root->left = trim_left(root->left);
        if (this->backtracking) return root;
        if (this->leftBound <= root->val)
        {
            this->backtracking = true;
            root->left = nullptr;
            return root;
        }
        if (root->right != nullptr)
            root->right = trim_left(root->right);
        if (this->backtracking) return root->right;
        return root;
    }
    TreeNode *trim_right(TreeNode *root)
    {
        if (root->right != nullptr)
            root->right = trim_right(root->right);
        if (this->backtracking) return root;
        if (root->val <= this->rightBound)
        {
            this->backtracking = true;
            root->right = nullptr;
            return root;
        }
        if (root->left != nullptr)
            root->left = trim_right(root->left);
        if (this->backtracking) return root->left;
        return root;
    }
    int leftBound, rightBound;
    bool backtracking;
public:
    // I did not bother writing code that frees the runtime heap
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        this->leftBound = L, this->rightBound = R;
        this->backtracking = false;
        if (root != nullptr) root = trim_left(root);
        this->backtracking = false;
        if (root != nullptr) root = trim_right(root);
        return root;
    }
};
