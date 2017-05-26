class Solution {
    vector<int> dp { 1, 1 };
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
        if (n < this->dp.size()) return this->dp[n];
        while (this->dp.size() <= n)
        {
            int sum = 0, last = this->dp.size() - 1;
            for (int pos = 0; pos <= last; pos++)
                sum += this->dp[pos] * this->dp[last - pos];
            this->dp.push_back(sum);
        }
        return this->dp[n];
    }
};
