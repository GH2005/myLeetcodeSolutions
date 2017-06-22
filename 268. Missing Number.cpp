class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int posOfN = -1;
        for (int pos = 0; pos < n; pos++)
        {
            while (nums[pos] != n && nums[pos] != pos)
                swap(nums[pos], nums[nums[pos]]);
            if (nums[pos] == n) posOfN = pos;
        }
        if (posOfN == -1) return n;
        else return posOfN;
    }
};
