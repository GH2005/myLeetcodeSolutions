class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int exEnds[3] = {};
        for (int pos = 0; pos < len; pos++) {
            int value = nums[pos];
            for (int key = 2; value <= key; --key) 
                nums[exEnds[key]++] = key;
        }
    }
};
