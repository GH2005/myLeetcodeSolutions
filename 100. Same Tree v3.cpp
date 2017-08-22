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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> stk;
        stk.push(p), stk.push(q);
        while (!stk.empty())
        {
            TreeNode *node1 = stk.top();
            stk.pop();
            TreeNode *node2 = stk.top();
            stk.pop();
            if (node1 == node2) continue;
            if (node1 != nullptr && node2 != nullptr)
            {
                if (node1->val != node2->val) return false;
                stk.push(node1->left), stk.push(node2->left);
                stk.push(node1->right), stk.push(node2->right);
            }
            else return false;
        }
        return true;
    }
};
