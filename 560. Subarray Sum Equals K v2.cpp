// editorial solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap;
        hashMap[100] = 1;
        int res = 0;
        int cumulativeSum = 100;
        for (int num : nums) {
            cumulativeSum += num;
            auto const it = hashMap.find(cumulativeSum - k);
            if (it != hashMap.end()) res += it->second;
            ++hashMap[cumulativeSum];
        }
        return res;
    }
};
