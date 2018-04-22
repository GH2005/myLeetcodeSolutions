ptrdiff_t const cArrayMaxLength = 10000;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ptrdiff_t const len = strs.size();
        assert(len <= ::cArrayMaxLength);
        using BitRow = std::bitset<::cArrayMaxLength>;
        BitRow hashTable[26];
        std::vector<std::array<ptrdiff_t, 26>> charCounts(len);
        for (ptrdiff_t i = 0; i < len; ++i) {
            for (char c : strs[i]) {
              hashTable[c - 'a'][i] = true;
              ++charCounts[i][c - 'a'];
            }
        }
        BitRow done;
        std::vector<std::vector<std::string>> res;
        BitRow theCompatible;
        for (ptrdiff_t i = 0; i < len; ++i) {
            if (done[i]) { continue; }
            theCompatible.set();
            for (char c : strs[i]) { theCompatible &= hashTable[c - 'a']; }
            res.emplace_back();
            for (ptrdiff_t j = i; j < len; ++j) {
                if (theCompatible[j] == false) { continue; }
                if (strs[j].size() == strs[i].size() && charCounts[i] == charCounts[j]) {
                  res.back().push_back(strs[j]);
                }
                else { theCompatible[j] = false; }
            }
            done |= theCompatible;
        }
        return res;
    }
};
