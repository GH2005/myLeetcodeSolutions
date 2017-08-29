class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while ((k %= n) != 0)
        {
            int start1 = nums.size() - n;
            int start2 = nums.size() - k;
            for (int i = 0; i < k; i++)
                swap(nums[start1 + i], nums[start2 + i]);
            n -= k;
        }
    }
};
