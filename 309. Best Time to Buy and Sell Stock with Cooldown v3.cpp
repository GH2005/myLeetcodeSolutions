class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        vector<int> dp(len+2);
        for (int start = len-2; 0 <= start; start--)
        {// range[start...len-1], dp[start]
            if (prices[start] >= prices[start+1])
            {
                dp[start] = dp[start+1];
                continue;
            }
            int accuDiff = 0, maxSofar = 0;
            for (int pos = start+1; pos < len; pos++)
            {// sell at pos
                accuDiff += prices[pos] - prices[pos-1];
                if (accuDiff < 0) accuDiff = 0;
                if (maxSofar < accuDiff)
                {
                    maxSofar = accuDiff;
                    dp[start] = max(dp[start], accuDiff + dp[pos+2]);
                }
            }
        }
        return dp[0];
    }
};
