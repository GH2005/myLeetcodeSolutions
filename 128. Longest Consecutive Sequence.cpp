class Solution {
  int prv_allAfter(int const baseIndex, std::vector<int> &results, std::vector<int> const &nexts) {
    int const thisIndex = nexts[baseIndex];
    if (nexts[thisIndex] == -1) { results[thisIndex] = 1; return 1; }
    if (results[thisIndex] != -100) return results[thisIndex];
    results[thisIndex] = 1 + prv_allAfter(thisIndex, results, nexts);
    return results[thisIndex];
  }
public:
    int longestConsecutive(vector<int>& nums) {
      int const len = nums.size();
      if (len < 2) { return len; }
      std::vector<int> nexts(len);
      std::unordered_map<int, int> toIndex;
      for (int i = 0; i < len; ++i) {
        int const num = nums[i];
        int const minusOne = num - 1;
        int const plusOne = num + 1;
        nexts[i] = -1;
        auto endIt = toIndex.cend();
        auto it = toIndex.find(num);
        if (it != endIt) continue;
        toIndex[num] = i;
        it = toIndex.find(minusOne);
        if (it != endIt) {
          nexts[it->second] = i;
        }
        it = toIndex.find(plusOne);
        if (it != endIt) {
          nexts[i] = it->second;
        }
      }
      std::vector<int> results(len, -100);
      int maxResult = 1;
      for (int i = 0; i < len; ++i) {
        if (results[i] == -100) {
          results[i] = 1 + prv_allAfter(i, results, nexts);
        } 
        maxResult = std::max(maxResult, results[i]);
      }
      return maxResult;
    }
};
