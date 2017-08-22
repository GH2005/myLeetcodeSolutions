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
        queue<TreeNode *> que;
        que.push(p), que.push(q);
        while (!que.empty())
        {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            if (node1 == node2) continue;
            if (node1 != nullptr && node2 != nullptr)
            {
                if (node1->val != node2->val) return false;
                que.push(node1->left), que.push(node2->left);
                que.push(node1->right), que.push(node2->right);
            }
            else return false;
        }
        return true;
    }
};
