class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp1 = 1, dp2 = 2;
        for (int pos = 2; pos < n; pos++)
            if (pos % 2 == 0) dp1 = dp1 + dp2;
            else dp2 = dp1 + dp2;
        if (n % 2 == 0) return dp2;
        else return dp1;
    }
};
