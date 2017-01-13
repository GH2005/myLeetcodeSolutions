class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // edge case, if applicable
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        
        // go over the array once
        for (int i = 0; i < n; i++) {// element nums[i], bucket i+1
            // a series of exchanges
            while (nums[i] != 0 && nums[i] != i + 1) {// a need for exchange
                // the two involved elements
                int &ele1 = nums[i];
                int &ele2 = nums[ele1 - 1];
        
                // if duplicate is found, break; else,switch them
                if (ele1 == ele2) {
                    res.push_back(ele1);
                    ele1 = ele2 = 0;
                    break;
                }
                else {
                    int tmp = ele1;
                    ele1 = ele2;
                    ele2 = tmp;
                }
            }
        }
        
        // return
        return res;
    }
};
