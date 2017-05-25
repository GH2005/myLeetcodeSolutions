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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        stack<TreeNode *> stk;
        TreeNode dummy(INT_MIN);
        TreeNode *aPopped = &dummy;
        int posPre = 0, posIn = 0;
        while ( posPre < preorder.size() )
        {
            stk.push( aPopped->right = new TreeNode(preorder[posPre++]) );
            while ( stk.top()->val != inorder[posIn] )
                stk.push( stk.top()->left = new TreeNode(preorder[posPre++]) );
            while ( !stk.empty() && stk.top()->val == inorder[posIn] )
            {
                aPopped = stk.top();
                stk.pop();
                posIn++;
            }
        }
        return dummy.right;
    }
};
