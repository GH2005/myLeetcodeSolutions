class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        // answer
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        
        // handle consecutive zeros first
        vector<int>::iterator it = find(nums.begin(), nums.end(), 0);
        if (it != nums.end()) {
            vector<int>::iterator it1 = it;
            int cZero = 0;
            while (it1 != nums.end() && *it1 == 0) { it1++; cZero++; }
            if (cZero >= 3) ans.push_back(vector<int>(3, 0));
            nums.erase(it+1, it1);
        }
        
        if (nums.size() < 3) return ans;
        
        // enumarate the middle number, skip repetitive ones
        for (int im = 1; im < nums.size() - 1; im++) {
            // skip post repetitive positive numbers
            if (nums[im] > 0 && nums[im] == nums[im-1]) continue;
            
            // skip preceding repetivie negative numbers
            if (nums[im] < 0 && nums[im] == nums[im+1]) continue;
            
            // double sides near each other
            // avoid repetition
            int i = 0, j = nums.size() - 1;
            while (i < im && j > im) {
                int sumAC = nums[i] + nums[j];
                if (sumAC < -nums[im]) {
                    while (nums[i] == nums[i+1]) i++;
                    i++;
                }
                else if (sumAC > -nums[im]) {
                    while (nums[j] == nums[j-1]) j--;
                    j--;
                }
                else {
                    vector<int> thisAns(3);
                    thisAns[0] = nums[i];
                    thisAns[1] = nums[im];
                    thisAns[2] = nums[j];
                    ans.push_back(thisAns);
                    while (nums[i] == nums[i+1]) i++;
                    while (nums[j] == nums[j-1]) j--;
                    i++; j--;
                }
            }
        }
        
        return ans;
    }
};
