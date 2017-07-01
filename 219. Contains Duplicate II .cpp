class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        int len = nums.size();
        if (len < 2) return false;
        unordered_map<int, int> um;
        for (int pos = 0; pos < len; pos++)
        {
            int value = nums[pos];
            auto it = um.find(value);
            if (it != um.end())
                if (pos - um[value] <= k) return true;
            um[value] = pos;
        }
        return false;
    }
};
