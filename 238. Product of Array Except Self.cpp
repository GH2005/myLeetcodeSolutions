class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t len = nums.size();
        vector<int> res(len);
        res[0] = nums[0];
        for (size_t pos = 1; pos < len; pos++)
            res[pos] = res[pos-1] * nums[pos];
        int rtPrdkt = 1;
        for (size_t pos = len-1; 0 < pos; pos--)
        {
            res[pos] = res[pos-1] * rtPrdkt;
            rtPrdkt *= nums[pos];
        }
        res[0] = rtPrdkt;
        return res; // copy elision
    }
};
