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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
        unordered_map<int, int> *aInorderPositions = nullptr,
        int *aPostorderStart = nullptr, int left = 0, int right = 0, bool isFirstCall = true)
    {
        if (isFirstCall)
        {
            if (postorder.size() == 0) return nullptr;
            aInorderPositions = new unordered_map<int, int>();
            for (int pos = 0; pos < inorder.size(); pos++) (*aInorderPositions)[inorder[pos]] = pos;
            aPostorderStart = new int(postorder.size()-1);
            left = 0, right = inorder.size() - 1;
        }
        if (right < left) return nullptr;
        
        int val = postorder[(*aPostorderStart)--];
        int inorderPos = (*aInorderPositions)[val];
        TreeNode *aRes = new TreeNode(val);
        aRes->right = this->buildTree(inorder, postorder, aInorderPositions, aPostorderStart, inorderPos+1, right, false);
        aRes->left = this->buildTree(inorder, postorder, aInorderPositions, aPostorderStart, left, inorderPos-1, false);
       
        if (isFirstCall) { delete aInorderPositions, aPostorderStart; }
        return aRes;
    }
};
