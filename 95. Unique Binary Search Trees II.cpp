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
    vector<vector<vector<TreeNode *>>> dp;
    vector<TreeNode *> dummy;
public:
    Solution() : dp( 2, vector<vector<TreeNode *>>(2, vector<TreeNode *>{new TreeNode(1)}) ), dummy(1) {}
    vector<TreeNode*> generateTrees(int n)
    {
        if ( n <= 0 ) return vector<TreeNode *>();
        if ( n < this->dp.size() ) return this->dp[1][n];
        // expand this->dp until n < size
        while ( this->dp.size() <= n )
        {
            int newValue = this->dp.size(), lastValue = newValue - 1;
            // expand the matrix by one
            this->dp.emplace_back(newValue+1);
            this->dp[newValue][newValue].push_back(new TreeNode(newValue));
            // fill the last (new) column
            int right = newValue;
            for (int left = lastValue; 1 <= left; --left)
            { // fill this->dp[left][right]
                this->dp[left].emplace_back();
                vector<TreeNode *> &set = this->dp[left][right];
                for (int root = left; root <= right; root++)
                {
                    int num1 = 0, num2 = 0;
                    vector<TreeNode *> &leftCollect = 
                        root == left ? (num1 = 1, this->dummy) : (num1 = this->dp[left][root-1].size(), this->dp[left][root-1]);
                    vector<TreeNode *> &rightCollect =
                        root == right ? (num2 = 1, this->dummy) : (num2 = this->dp[root+1][right].size(), this->dp[root+1][right]);
                    for (int pos1 = 0; pos1 < num1; pos1++) for (int pos2 = 0; pos2 < num2; pos2++)
                    {
                        set.push_back(new TreeNode(root));
                        set.back()->left = leftCollect[pos1];
                        set.back()->right = rightCollect[pos2];
                    }
                }
            }
        }
        return this->dp[1][n];
    }
};
