class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (&nums == nullptr) return res;
        int len = nums.size();
        if (len < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        // search for quadruplets
        vector<int> currQuadruplet;
        currQuadruplet.reserve(4);
        for (int iFirst = 0; iFirst < len - 3; iFirst++) {
            int vFirst = nums[iFirst];
            if (iFirst > 0 && vFirst == nums[iFirst-1]) continue;
            currQuadruplet.push_back(vFirst);
            for (int iSecond = iFirst+1; iSecond < len - 2; iSecond++) {
                int vSecond = nums[iSecond];
                if (iSecond > iFirst+1 && vSecond == nums[iSecond-1]) continue;
                currQuadruplet.push_back(vSecond);
                
                // search from both ends of the remaining range
                int left = iSecond + 1, right = len - 1;
                int tempTarg = target - vFirst - vSecond;
                while (left < right) {
                    bool leftMoving = false, rightMoving = false;
                    int vThird = nums[left], vForth = nums[right];
                    int twoSum = vThird + vForth;
                    if (twoSum == tempTarg) {
                        currQuadruplet.push_back(vThird);
                        currQuadruplet.push_back(vForth);
                        res.push_back(currQuadruplet);
                        currQuadruplet.pop_back();
                        currQuadruplet.pop_back();
                        leftMoving = rightMoving = true;
                    }
                    else if (twoSum < tempTarg) leftMoving = true;
                    else rightMoving = true;
                    // move boundaries
                    if (leftMoving) {
                        left++;
                        while (left < len && nums[left] == nums[left-1]) left++;
                    }
                    if (rightMoving) {
                        right --;
                        while(right > iSecond && nums[right] == nums[right+1]) right --;
                    }
                }
                currQuadruplet.pop_back();
            }
            currQuadruplet.pop_back();
        }
        return res;
    }
};
