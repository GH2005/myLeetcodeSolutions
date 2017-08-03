class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int left = 1, right = n; /*left <= right*/;)
        {
            int mid = left + (right-left) / 2;
            bool midExists = false;
            int cSmaller = 0;
            for (int value : nums)
            {
                if (value == mid)
                {
                    if (midExists) return mid;
                    else midExists = true;
                }
                else if (value < mid) cSmaller++;
            }
            if (cSmaller <= mid - 1) left = mid + 1;
            else right = mid - 1;
        }
        // it should not reach here
    }
};
