class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 1 || n <= 1) return 1;
		std::array<int, 100> dp;
		dp.fill(1);
		for (size_t row = m - 2; row < SIZE_MAX; --row) {
			for (size_t col = n - 2; col < SIZE_MAX; --col) {
				dp[col] = dp[col] + dp[col + 1];
			}
		}
		return dp[0];
	}
};
