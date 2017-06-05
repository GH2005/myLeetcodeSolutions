class Solution {
    vector<int> dp;
public:
    int maxProfit(vector<int>& prices, int start = 0) {
        if (start == 0) this->dp = vector<int>(prices.size()+2, -1);
        if (0 <= this->dp[start]) return this->dp[start];
        int maxCombSofar = 0, accuDiff = 0, maxAccuDiffSofar = 0;
        for (int pos = start+1; pos < prices.size(); pos++)
        {
            accuDiff += prices[pos] - prices[pos-1];
            if (accuDiff < 0) accuDiff = 0;
            if (maxAccuDiffSofar < accuDiff)
            {
                maxAccuDiffSofar = accuDiff;
                maxCombSofar = max(maxCombSofar, accuDiff + this->maxProfit(prices, pos+2));
            }
        }
        this->dp[start] = maxCombSofar;
        return maxCombSofar;
    }
};
