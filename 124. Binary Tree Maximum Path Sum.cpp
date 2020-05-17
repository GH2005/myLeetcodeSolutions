/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxPathSum(TreeNode const * const root) const noexcept
    {
        int rtn = std::numeric_limits<int>::min();
        if (root)
            this->VerticalSum(root, rtn);
        return rtn;
    }
private:
    int VerticalSum(TreeNode const * const root, int & globalSum) const noexcept
    {
        int const leftVerticalSum
            = std::max(root->left  ? this->VerticalSum(root->left, globalSum)  : std::numeric_limits<int>::min(), 0);
        int const rightVerticalSum
            = std::max(root->right ? this->VerticalSum(root->right, globalSum) : std::numeric_limits<int>::min(), 0);
        
        int const localSum = root->val + leftVerticalSum + rightVerticalSum;
        globalSum = std::max(globalSum, localSum);
        
        return root->val + std::max(leftVerticalSum, rightVerticalSum);
    }
};
