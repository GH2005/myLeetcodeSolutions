class Solution {
    int tgt, currSum;
    size_t len;
    int cWays;
    vector<int> *aNums;
    vector<int> *aSuffixSums;
    void bt(size_t pos)
    {
        int num = (*aNums)[pos++];
        currSum += num;
        if (pos == len) currSum == tgt ? cWays++ : 0;
        else if (std::abs(tgt - currSum) <= (*aSuffixSums)[pos]) bt(pos);
        currSum -= num;
        currSum -= num;
        if (pos == len) currSum == tgt ? cWays++ : 0;
        else if (std::abs(tgt - currSum) <= (*aSuffixSums)[pos]) bt(pos);
        currSum += num;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        tgt = S, currSum = 0, len = nums.size(), cWays = 0, aNums = &nums;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        vector<int> suffixSums(nums);
        int sum = std::accumulate(suffixSums.begin(), suffixSums.end(), 0);
        for (int &suffixSum : suffixSums)
            sum -= suffixSum, suffixSum += sum;
        aSuffixSums = &suffixSums;
        bt(0);
        return cWays;
    }
};
