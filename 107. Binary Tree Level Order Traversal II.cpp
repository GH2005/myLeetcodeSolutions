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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            res.emplace_back();
            vector<int> &v = res.back();
            v.reserve(len);
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
