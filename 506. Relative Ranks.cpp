class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int, std::greater<int>> originPosOf;
        for (int pos = 0; pos < nums.size(); pos++)
            originPosOf[nums[pos]] = pos;
        vector<string> res(nums.size());
        auto it = originPosOf.begin();
        if (it != originPosOf.end()) res[it->second] = "Gold Medal", it++;
        if (it != originPosOf.end()) res[it->second] = "Silver Medal", it++;
        if (it != originPosOf.end()) res[it->second] = "Bronze Medal", it++;
        int ordinal = 4;
        while (it != originPosOf.end())
            res[it->second] = to_string(ordinal++), it++;
        return res;
    }
};
