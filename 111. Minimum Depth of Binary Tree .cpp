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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            res++;
            int numToPop = q.size();
            for (int i = 0; i < numToPop; i++)
            {
                TreeNode *node = q.front(); q.pop();
                if (node->left == node->right) return res;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return res;
    }
};
