class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int left = 0, right = left; right < prices.size(); right++)
        {
            int diff = prices[right] - prices[left];
            if (diff < 0) left = right;
            else res = max(res, diff);
        }
        return res;
    }
};
