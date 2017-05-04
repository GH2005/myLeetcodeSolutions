class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int posSeeker = 1, posBase = 0;
        while (posSeeker < len)
            if (nums[posBase] < nums[posSeeker++])
                swap(nums[++posBase], nums[posSeeker-1]);
        return ++posBase;
    }
};
