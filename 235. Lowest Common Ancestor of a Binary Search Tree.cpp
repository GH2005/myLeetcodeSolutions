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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!(root && p && q)) return nullptr;
        if (p == q || p->val == q->val) return p;
        int v1 = p->val, v2 = q->val, v = root->val;
        if (v == v1) return p;
        if (v == v2) return q;
        if ((v1 < v && v < v2) || (v2 < v && v < v1)) return root;
        if (v1 < v) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};
