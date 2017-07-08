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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int numToPop = 1;
        int res = 0;
        while (0 < numToPop)
        {
            res++;
            int tmpNumToPop = 0;
            for (int i = 0; i < numToPop; i++)
            {
                TreeNode *node = q.front(); q.pop();
                if (node->left != nullptr) { q.push(node->left); tmpNumToPop++; }
                if (node->right != nullptr) { q.push(node->right); tmpNumToPop++; }
            }
            numToPop = tmpNumToPop;
        }
        return res;
    }
};
