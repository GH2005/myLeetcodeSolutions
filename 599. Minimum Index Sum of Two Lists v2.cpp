class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> uomap;
        for (int pos = 0; pos < list1.size(); pos++)
            uomap[list1[pos]] = pos;
        // walk through list2 and add strings with smallest sum
        vector<string> res;
        int minSumSofar = INT_MAX;
        for (int pos = 0; pos < list2.size(); pos++)
        {
            auto it = uomap.find(list2[pos]);
            if (it != uomap.end())
            {
                int sum = it->second + pos;
                if (sum < minSumSofar) res.clear(), minSumSofar = sum;
                if (sum == minSumSofar) res.push_back(list2[pos]);
            }
        }
        return res;
    }
};
