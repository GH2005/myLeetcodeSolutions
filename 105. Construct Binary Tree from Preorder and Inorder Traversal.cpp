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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
        unordered_map<int, int> *aInorderPositions = nullptr,
        int *aPreorderStart = nullptr, int left = 0, int right = 0, bool isFirstCall = true)
    {
        if (isFirstCall)
        {
            if (preorder.size() == 0) return nullptr;
            aInorderPositions = new unordered_map<int, int>();
            for (int pos = 0; pos < inorder.size(); pos++) (*aInorderPositions)[inorder[pos]] = pos;
            aPreorderStart = new int(0);
            left = 0, right = inorder.size() - 1;
        }
        if (right < left) return nullptr;
        
        int val = preorder[(*aPreorderStart)++];
        int inorderPos = (*aInorderPositions)[val];
        TreeNode *aRes = new TreeNode(val);
        aRes->left = this->buildTree(preorder, inorder, aInorderPositions, aPreorderStart, left, inorderPos - 1, false);
        aRes->right = this->buildTree(preorder, inorder, aInorderPositions, aPreorderStart, inorderPos + 1, right, false);
       
        if (isFirstCall) { delete aInorderPositions, aPreorderStart; }
        return aRes;
    }
};
