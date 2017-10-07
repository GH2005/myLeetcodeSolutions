class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> occurrences;
        for (int v : nums) occurrences[v]++;
        int lenHarmo = 0;
        if (occurrences.size() < 2) return lenHarmo;
        for (auto it1 = occurrences.begin(), it2 = ++occurrences.begin();
            it2 != occurrences.end(); it1++, it2++)
            if (it1->first + 1 == it2->first)
                lenHarmo = max(lenHarmo, it1->second + it2->second);
        return lenHarmo;
    }
};
