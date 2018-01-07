class Solution {
    int tgt, currSum;
    size_t len;
    int cWays;
    vector<int> *aNums;
    void bt(size_t pos)
    {
        int num = (*aNums)[pos++];
        currSum += num;
        if (pos == len) currSum == tgt ? cWays++ : 0;
        else bt(pos);
        currSum -= num;
        currSum -= num;
        if (pos == len) currSum == tgt ? cWays++ : 0;
        else bt(pos);
        currSum += num;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        tgt = S, currSum = 0, len = nums.size(), cWays = 0, aNums = &nums;
        bt(0);
        return cWays;
    }
};
