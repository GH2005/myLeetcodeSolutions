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
private:
    struct QueueElement {
        TreeNode *node;
        int depth;
        QueueElement(TreeNode *n, int d) :node(n), depth(d) {}
    };
public:
    vector<int> rightSideView(TreeNode* root) {
        // prepare the response
        vector<int> res;
        if (root == nullptr) return res;
        
        // BFS; adding items into res
        queue<QueueElement> q;
        q.push(QueueElement(root, 0));
        while (!q.empty()) {
            // the node
            QueueElement qe = q.front();
            q.pop();
            TreeNode *leftDesc = qe.node->left;
            TreeNode *rightDesc = qe.node->right;
            int value = qe.node->val;
            int d = qe.depth;
            
            // add a new element into res or update an existent element
            if (res.size() == d) {
                res.push_back(value);
            }
            else { // update an existent one
                res[d] = value;
            }
            
            // add descendants into the queue
            if (leftDesc) q.push(QueueElement(leftDesc, d+1));
            if (rightDesc) q.push(QueueElement(rightDesc, d+1));
        }
        
        // return res
        return res;
    }
};
