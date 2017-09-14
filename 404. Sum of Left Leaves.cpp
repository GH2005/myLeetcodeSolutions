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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        stack<TreeNode *> stk;
        stk.push(root); stk.push(nullptr); 
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            TreeNode *node2 = stk.top();
            stk.pop();
            if (node2 != nullptr)
                if (node2->left != nullptr
                || node2->right != nullptr)
                    stk.push(node2->right),
                    stk.push(node2->left);
            if (node != nullptr)
            {
                if (node->left == nullptr
                && node->right == nullptr)
                    res += node->val;
                else
                    stk.push(node->right),
                    stk.push(node->left);
            }
        }
        return res;
    }
};
