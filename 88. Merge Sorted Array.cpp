class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = m + n - 1;
        --m, --n;
        while (0 <= m && 0 <= n) {
            if (nums1[m] < nums2[n]) nums1[right--] = nums2[n--];
            else nums1[right--] = nums1[m--];
        }
        // handle the remaining items in the longer array
        while (0 <= m) nums1[right--] = nums1[m--];
        while (0 <= n) nums1[right--] = nums2[n--];
    }
};
