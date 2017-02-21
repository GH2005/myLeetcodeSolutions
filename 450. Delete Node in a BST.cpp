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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode *aDummy = new TreeNode(-1);   // delete it before return
        aDummy->left = root;
        TreeNode *addr = root;
        TreeNode **aLink = &aDummy->left;
        TreeNode **aTgtLink = nullptr;
        while (addr) {
            int val = addr->val;
            if (key == val) { aTgtLink = aLink; break; }
            else if (key < val) { aLink = &addr->left; addr = addr->left; }
            else { aLink = &addr->right; addr = addr->right; }
        }
        if (!aTgtLink) { delete aDummy; return root; }
        TreeNode *aLeft = (*aTgtLink)->left;
        TreeNode *aRight = (*aTgtLink)->right;
        delete (*aTgtLink);
        // swapping a leaf node up to the emptied address
        if (aLeft) {
            if (!aLeft->right) {
                (*aTgtLink) = aLeft;
                aLeft->right = aRight;
            }
            else {
                addr = aLeft->right;
                aLink = &aLeft->right;
                while (addr->right) { aLink = &addr->right; addr = addr->right; }
                (*aLink) = addr->left;
                (*aTgtLink) = addr;
                addr->left = aLeft, addr->right = aRight;
            }
        }
        else if (aRight) {
            if (!aRight->left) {
                (*aTgtLink) = aRight;
                aRight->left = nullptr;
            }
            else {
                addr = aRight->left;
                aLink = &aRight->left;
                while (addr->left) { aLink = &addr->left; addr = addr->left; }
                (*aLink) = addr->right;
                (*aTgtLink) = addr;
                addr->left = aLeft, addr->right = aRight;
            }
        }
        else {
            (*aTgtLink) = nullptr;
        }
        root = aDummy->left;
        delete aDummy;
        return root;
    }
};
