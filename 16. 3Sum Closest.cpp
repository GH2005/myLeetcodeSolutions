class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // prerequisites
        assert(nums.size() >= 3);
        sort(nums.begin(), nums.end());
        
        // result
        int res = 0;
        int udiff = INT_MAX;
        
        // main process
        for (int im = 1; im < nums.size() - 1; im++) {  // every possible middle intt
            int ileft = 0, iright = nums.size() - 1;
            // contracting inward
            while (ileft < im && iright > im) {
                // evaluate
                int curr_sum = nums[ileft]+nums[im]+nums[iright];
                int curr_diff = curr_sum - target;
                if (curr_diff == 0) return target;
                if (abs(curr_diff) < udiff) {
                    udiff = abs(curr_diff);
                    res = curr_sum;
                }
                // update
                if (curr_diff < 0) ileft++;
                else iright--;
            }
        }
        
        // return
        return res;
    }
};
