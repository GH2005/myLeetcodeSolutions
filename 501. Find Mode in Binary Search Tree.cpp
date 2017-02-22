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
    vector<int> res;
    int prev = 0;
    int cRepeat = 0;
    int cVisited = 0;
    int maxRepeatSoFar = 0;
    void dfs(TreeNode *root) {
        if (!root) return;
        int val = root->val;
        this->dfs(root->left);
        // visit the root
        if (this->cVisited == 0) { this->prev = val; this->cRepeat = 1; }
        else {// not the first element
            if (val == this->prev) {
                this->cRepeat ++;    
            }
            else {// a different value is seen
                if (this->maxRepeatSoFar < this->cRepeat) {
                    this->maxRepeatSoFar = this->cRepeat;
                    this->res.clear();
                    this->res.push_back(this->prev);
                }
                else if (this->maxRepeatSoFar == this->cRepeat) {
                    this->res.push_back(this->prev);
                }
                this->prev = val;
                this->cRepeat = 1;
            }
        }
        this->cVisited ++;
        this->dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        this->res.clear();
        if (!root) return this->res;
        // prepare for the in-order traversal
        this->cVisited = 0;
        this->maxRepeatSoFar = 0;
        
        // traversal
        this->dfs(root);
        
        // the last accounting
        if (this->maxRepeatSoFar < this->cRepeat) {
            this->maxRepeatSoFar = this->cRepeat;
            this->res.clear();
            this->res.push_back(this->prev);
        }
        else if (this->maxRepeatSoFar == this->cRepeat) {
            this->res.push_back(this->prev);
        }
        
        return this->res;
    }
};
