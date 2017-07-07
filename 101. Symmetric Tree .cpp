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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        vector<TreeNode *> buffer;
        vector<TreeNode *> tmpBuffer;
        buffer.push_back(root->left);
        buffer.push_back(root->right);
        while (!buffer.empty())
        {
            int left = 0, right = buffer.size() - 1;
            while (left < right && (buffer[left] == buffer[right]
                || (buffer[left] != nullptr && buffer[right] != nullptr
                    && buffer[left]->val == buffer[right]->val)))
                left++, right--;
            if (left < right) return false;
            for (TreeNode *a : buffer)
            {
                if (a == nullptr) continue;
                tmpBuffer.push_back(a->left);
                tmpBuffer.push_back(a->right);
            }
            std::swap(buffer, tmpBuffer);
            tmpBuffer.clear();
        }
        return true;
    }
};
