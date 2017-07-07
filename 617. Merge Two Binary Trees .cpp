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
        TreeNode *aMergedRoot =
            new TreeNode((t1 == nullptr ? 0 : t1->val) + (t2 == nullptr ? 0 : t2->val));
        queue<TreeNode *> q;
        q.push(aMergedRoot), q.push(t1), q.push(t2);
        while (!q.empty())
        {
            TreeNode *aMergedNode = q.front(); q.pop();
            TreeNode *aNode1 = q.front(); q.pop();
            TreeNode *aNode2 = q.front(); q.pop();
            
            TreeNode *aMergedLeftNode = nullptr, *aMergedRightNode = nullptr;
            if ((aNode1 != nullptr && aNode1->left != nullptr) || (aNode2 != nullptr && aNode2->left != nullptr))
                aMergedLeftNode = new TreeNode((aNode1 != nullptr && aNode1->left != nullptr ? aNode1->left->val : 0)
                                                        + (aNode2 != nullptr && aNode2->left != nullptr ? aNode2->left->val : 0));
            if (aMergedLeftNode != nullptr){
                q.push(aMergedLeftNode), q.push(aNode1 == nullptr ? nullptr : aNode1->left),
                q.push(aNode2 == nullptr ? nullptr :aNode2->left);
                aMergedNode->left = aMergedLeftNode;
            }
            if ((aNode1 != nullptr && aNode1->right != nullptr) || (aNode2 != nullptr && aNode2->right != nullptr))
                aMergedRightNode = new TreeNode((aNode1 != nullptr && aNode1->right != nullptr ? aNode1->right->val : 0)
                                                        + (aNode2 != nullptr && aNode2->right != nullptr ? aNode2->right->val : 0));
            if (aMergedRightNode != nullptr) {
                q.push(aMergedRightNode), q.push(aNode1 == nullptr ? nullptr : aNode1->right),
                q.push(aNode2 == nullptr ? nullptr : aNode2->right);
                aMergedNode->right = aMergedRightNode;
            }
        }
        return aMergedRoot;
    }
};
