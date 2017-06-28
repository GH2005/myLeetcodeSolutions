// dp version
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        if (len == 3) return max(nums[0] + nums[2], nums[1]);
        int prevA = nums[len-1], b = nums[len-2],
            a = nums[len-3] + nums[len-1], prevB = 0;
        bool doB = true;
        for (int pos = len-4; 0 <= pos; pos--, doB = !doB)
        {
            if (doB)
            {
                prevB = b;
                b = max(b, prevA) + nums[pos];
            }
            else
            {
                prevA = a;
                a = max(a, prevB) + nums[pos];
            }
        }
        return max(a, b);
    }
};
