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
  TreeNode *m_selectedNode = nullptr;
  size_t prv_howMany(TreeNode *const root, TreeNode const *const p, TreeNode const *const q) noexcept {
    size_t howMany = 0;
    if (root == p || root == q) { ++howMany; }
    
    howMany += root->left ? prv_howMany(root->left, p, q) : 0;
    if (howMany >= 2) { if (!m_selectedNode) { m_selectedNode = root; } return howMany; }
    
    howMany += root->right ? prv_howMany(root->right, p, q) : 0;
    if (howMany >= 2) { if (!m_selectedNode) { m_selectedNode = root; } return howMany; }
    
    return howMany;
  }
public:
    TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) { return nullptr; }
      prv_howMany(root, p, q);
      return m_selectedNode;
    }
};
