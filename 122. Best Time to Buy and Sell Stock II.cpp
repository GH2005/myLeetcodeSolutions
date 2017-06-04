class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int pos = 1; pos < prices.size(); pos++)
        {
            int diff = prices[pos] - prices[pos-1];
            if (0 < diff) sum += diff;
        }
        return sum;
    }
};
