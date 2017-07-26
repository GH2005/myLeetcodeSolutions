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
    bool is_identical(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        return root1->val == root2->val && is_identical(root1->left, root2->left)
                && is_identical(root1->right, root2->right); 
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t != nullptr) return false;
        return this->is_identical(s, t) || this->isSubtree(s->left, t)
            || this->isSubtree(s->right, t);
    }
};
