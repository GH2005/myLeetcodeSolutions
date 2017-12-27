class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*construct the hash table*/
        std::unordered_map<int, size_t> uomap;
        for (int val : nums) uomap[val]++;
        /*sort the values*/
        auto val_cmp = [&uomap](const int &val1, const int &val2)->bool
        {
            return uomap[val1] > uomap[val2];
        };
        size_t szCurr = 0;
        vector<int> hp(uomap.size());
        for (auto it = uomap.begin(); it != uomap.end(); it++)
            hp[szCurr++] = it->first;
        std::sort(hp.begin(), hp.end(), val_cmp);
        hp.resize(k);
        return hp;
    }
};
