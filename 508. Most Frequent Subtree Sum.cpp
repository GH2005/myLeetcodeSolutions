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
    unordered_map<int, int> uomap;
    int maxFreqSofar;
    int postorder(TreeNode *root)
    {
        int sum = root->val;
        if (root->left != nullptr)
            sum += this->postorder(root->left);
        if (root->right != nullptr)
            sum += this->postorder(root->right);
        this->maxFreqSofar = max(maxFreqSofar, ++ this->uomap[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        this->uomap.clear();
        this->maxFreqSofar = 0;
        this->postorder(root);
        for (pair<int, int> item : this->uomap)
            if (item.second == this->maxFreqSofar)
                res.push_back(item.first);
        return res;
    }
};
