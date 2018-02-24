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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> response;
        if (root == nullptr) return response;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            size_t levelWidth = q.size();
            response.emplace_back(levelWidth);
            for (int i = 0; i < levelWidth; ++i) {
                TreeNode *nodeAddress = q.front(); q.pop();
                response.back()[i] = nodeAddress->val;
                if (nodeAddress->left != nullptr) {
                    q.push(nodeAddress->left);
                }
                if (nodeAddress->right != nullptr) {
                    q.push(nodeAddress->right);
                }
            }
        }
        return response;
    }
};
