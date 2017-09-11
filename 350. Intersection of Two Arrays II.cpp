class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int pos1 = 0, pos2 = 0; pos1 < nums1.size() && pos2 < nums2.size();)
        {
            if (nums1[pos1] == nums2[pos2]) res.push_back(nums1[pos1]), pos1++, pos2++;
            else if (nums1[pos1] < nums2[pos2]) pos1++;
            else pos2++;
        }
        return res;
    }
};
