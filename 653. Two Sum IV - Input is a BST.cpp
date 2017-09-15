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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        vector<int> inorder;
        stack<TreeNode *> stk;
        stk.push(root);
        unordered_set<TreeNode *> toBeAccessed;
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            if (toBeAccessed.find(node) != toBeAccessed.end())
            {
                inorder.push_back(node->val);
                stk.pop();
                toBeAccessed.erase(node);
                if (node->right != nullptr) stk.push(node->right);
            }
            else
            {
                toBeAccessed.insert(node);
                if (node->left != nullptr) stk.push(node->left);
            }
        }
        // two pointers
        if (inorder.size() < 2) return false;
        int left = 0, right = inorder.size() - 1;
        while (left < right)
        {
            int sum = inorder[left] + inorder[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }
};
