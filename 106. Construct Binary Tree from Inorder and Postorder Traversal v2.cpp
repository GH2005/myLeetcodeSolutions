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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        stack<TreeNode *> stk;
        TreeNode dummy(INT_MIN);
        TreeNode *aPopped = &dummy;
        int posPost = postorder.size() - 1, posIn = inorder.size() - 1;
        while ( 0 <= posPost )
        {
            stk.push( aPopped->left = new TreeNode(postorder[posPost--]) );
            while ( stk.top()->val != inorder[posIn] )
                stk.push( stk.top()->right = new TreeNode(postorder[posPost--]) );
            while ( !stk.empty() && stk.top()->val == inorder[posIn] )
            {
                aPopped = stk.top();
                stk.pop();
                --posIn;
            }
        }
        return dummy.left;
    }
};
