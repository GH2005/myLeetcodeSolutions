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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        int v1 = 0, v2 = 0;
        TreeNode *aT1Left = 0, *aT1Right = 0, *aT2Left = 0, *aT2Right = 0;
        if (t1 != nullptr)
        {
            v1 = t1->val;
            aT1Left = t1->left;
            aT1Right = t1->right;
        }
        if (t2 != nullptr)
        {
            v2 = t2->val;
            aT2Left = t2->left;
            aT2Right = t2->right;
        }
        TreeNode *aMergedNode = new TreeNode(v1 + v2);
        aMergedNode->left = this->mergeTrees(aT1Left, aT2Left);
        aMergedNode->right = this->mergeTrees(aT1Right, aT2Right);
        return aMergedNode;
    }
};
