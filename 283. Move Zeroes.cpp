class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int seeker = 0, base = 0;
        while (seeker < len) {
            int value = nums[seeker++];
            if (value != 0) nums[base++] = value;
        }
        while (base < len) nums[base++] = 0;
    }
};
