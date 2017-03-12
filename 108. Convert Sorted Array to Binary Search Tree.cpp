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
    vector<int> *aNums;
    void binary_search(TreeNode *&topDown, int left, int right) {
        if (right < left) return;
        if (left == right) { topDown = new TreeNode((*this->aNums)[left]); return; }
        int mid = (right - left) / 2 + left;
        topDown = new TreeNode((*this->aNums)[mid]);
        this->binary_search(topDown->left, left, mid - 1);
        this->binary_search(topDown->right, mid + 1, right);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(nums[0]);
        int left = 0, right = len - 1;
        int mid = (right - left) / 2 + left;
        TreeNode *aRoot = new TreeNode(nums[mid]);
        this->aNums = &nums;
        this->binary_search(aRoot->left, left, mid - 1);
        this->binary_search(aRoot->right, mid + 1, right);
        return aRoot;
    }
};
