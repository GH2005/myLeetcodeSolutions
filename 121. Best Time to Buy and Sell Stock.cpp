class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int left = 0, right = left; right < prices.size(); right++)
        {
            if (prices[left] > prices[right]) left = right;
            res = max(res, prices[right] - prices[left]);
        }
        return res;
    }
};
