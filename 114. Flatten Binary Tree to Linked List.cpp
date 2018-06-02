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
  TreeNode m_dummy = {2};
  TreeNode *m_lastProcessedNode = &m_dummy;
public:
  void flatten(TreeNode* root, bool const isFirstCall = true) {
    if (root == nullptr) return;
    if (isFirstCall) m_lastProcessedNode = &m_dummy;
    TreeNode * const leftChild = root->left, * const rightChild = root->right;
    root->left = nullptr, root->right = nullptr;
    m_lastProcessedNode = m_lastProcessedNode->right = root;
    this->flatten(leftChild, false);
    this->flatten(rightChild, false);
  }
};
