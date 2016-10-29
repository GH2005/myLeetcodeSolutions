#define MAX_NUM 500
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // padding
        int balloons[MAX_NUM+2];
        for (int i = 0; i < nums.size(); i++) balloons[i+1] = nums[i];
        int cBalloons = nums.size() + 2;
        balloons[0] = balloons[cBalloons-1] = 1;
        
        // the dp table
        int dp[MAX_NUM+2][MAX_NUM+3];
        memset(dp, 0, sizeof(int)*(MAX_NUM+2)*(MAX_NUM+3));
        
        // from small ranges to large ones; current computation benefits from previous results
        for (int len = 1; len <= nums.size(); len++) {// ranges of length len
            for (int left = 1; left <= cBalloons - 1 - len; left++) {// range [left...left+len)
                int right = left + len; // exclusive
                for (int i = left; i < right; i++) { // the last burst balloon is i
                    int value = dp[left][i] + dp[i+1][right] + balloons[left-1] * balloons[i] * balloons[right];
                    if (value > dp[left][right]) dp[left][right] = value;
                }
            }
        }
        
        // return the max num of coins for the largest range
        return dp[1][cBalloons-1];
    }
};
