class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        if (height == 0) return 0;
        vector<int> dp(triangle.back());
        for (int level = height - 2; 0 <= level; --level) {
            for (int pos = 0; pos <= level; pos++)
                dp[pos] = min(dp[pos], dp[pos+1]) + triangle[level][pos];
        }
        return dp[0];
    }
};
