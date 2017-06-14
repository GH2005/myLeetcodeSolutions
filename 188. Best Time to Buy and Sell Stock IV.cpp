// with partial reference to hanhongsun's solution
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }

        len = min(int(prices.size() / 2 + 1), k+1);
        int buy[len], sell[len] = {};
        for (int i = 0; i < len; i++) buy[i] = INT_MIN;
        for (int price : prices)
            for (int pos = 1; pos <= len-1; pos++)
            {
                buy[pos] = max(buy[pos], sell[pos-1] - price);
                sell[pos] = max(sell[pos], buy[pos] + price);
            }
        return sell[len-1];
    }
};
