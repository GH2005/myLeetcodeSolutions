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
    struct StackEle {
        TreeNode *pNode;
        int state;
        StackEle(TreeNode *p, int s) :pNode(p), state(s) {}
        // state: 0 --- first pushed; 1 --- left tree returns; 2 --- right tree returns
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        
        stack<Solution::StackEle> s;
        s.push(StackEle(root, 0));
        while (!s.empty()) {
            StackEle &se = s.top();
            if (se.state == 0) {
                if (se.pNode->left != nullptr) s.push(StackEle(se.pNode->left, 0));
                se.state = 1;
            }
            else if (se.state == 1) {
                res.push_back(se.pNode->val);
                if (se.pNode->right != nullptr) s.push(StackEle(se.pNode->right, 0));
                se.state = 2;
            }
            else {
                s.pop();
            }
        }
        
        return res;
    }
};
