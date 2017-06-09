class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        // anchoring the left border
        vector<int> leftAnchored(len);
        for (int minV = INT_MAX, maxProfit = 0, pos = 0; pos < len; pos++)
        {
            int v = prices[pos];
            if (v < minV) minV = v;
            else maxProfit = max(maxProfit, v - minV);
            leftAnchored[pos] = maxProfit;
        }
        // anchoring the right border
        vector<int> rightAnchored(len);
        for (int maxV = INT_MIN, maxProfit = 0, pos = len-1; 0 <= pos; pos--)
        {
            int v = prices[pos];
            if (maxV < v) maxV = v;
            else maxProfit = max(maxProfit, maxV - v);
            rightAnchored[pos] = maxProfit;
        }
        // find the maximum sum
        for (int boundary = 0; boundary < len; boundary++)
            res = max(res, leftAnchored[boundary] + rightAnchored[boundary]);
        return res;
    }
};
