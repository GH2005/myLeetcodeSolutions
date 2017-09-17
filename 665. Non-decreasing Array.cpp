class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return true;
        int modifiedPos = -1, originVal = 0;
        // left to right pass
        bool successful = true;
        for (int pos = 1; pos < len; pos++)
        {
            if (nums[pos-1] > nums[pos])
            {
                if (modifiedPos != -1)
                {
                    successful = false;
                    break;
                }
                else
                {
                    modifiedPos = pos;
                    originVal = nums[pos];
                    nums[pos] = nums[pos-1];
                }
            }
        }
        if (modifiedPos != -1) nums[modifiedPos] = originVal;
        modifiedPos = -1;
        if (successful) return true;
        // right-to-left pass
        successful = true;
        for (int pos = len - 2; 0 <= pos; pos--)
        {
            if (nums[pos] > nums[pos+1])
            {
                if (modifiedPos != -1)
                {
                    successful = false;
                    break;
                }
                else
                {
                    modifiedPos = pos;
                    originVal = nums[pos];
                    nums[pos] = nums[pos+1];
                }
            }
        }
        if (modifiedPos != -1) nums[modifiedPos] = originVal;
        if (successful) return true;
        else return false;
    }
};
