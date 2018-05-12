// editorial solution: exception handling seems slow
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap;
        hashMap[100] = 1;
        int res = 0;
        int cumulativeSum = 100;
        for (int num : nums) {
            cumulativeSum += num;
            try {
                res += hashMap.at(cumulativeSum - k);
            }
            catch(...) {}
            ++hashMap[cumulativeSum];
        }
        return res;
    }
};
