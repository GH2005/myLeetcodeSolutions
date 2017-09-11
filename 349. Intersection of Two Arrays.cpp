class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> uomap;
        for (int v : nums1)
            if (uomap[v] == 0) uomap[v] = 1;
        for (int v : nums2)
            if (uomap[v] == 1)
                res.push_back(v), uomap[v]++;
        return res;
    }
};
