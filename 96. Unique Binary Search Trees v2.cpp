class Solution {
    vector<long long> dp { 1, 1 };
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
        if (n < this->dp.size()) return this->dp[n];
        while (this->dp.size() <= n)
        {
            int last = this->dp.size() - 1;
            this->dp.push_back( this->dp[last] * 2 * (2*last+1) / (last+2) );
        }
        return this->dp[n];
    }
};
