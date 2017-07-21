// I don't quite understand
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if (len == 0) return res;
        int cand1 = 100, cand2 = 200, c1 = 0, c2 = 0;
        for (int value : nums)
        {
            if (value == cand1) c1++;
            else if (value == cand2) c2++;
            else if (c1 == 0)
            {
                cand1 = value;
                c1 = 1;
            }
            else if (c2 == 0)
            {
                cand2 = value;
                c2 = 1;
            }
            else c1--, c2--;
        }
        if (len / 3 < count(nums.begin(), nums.end(), cand1)) res.push_back(cand1);
        if (len / 3 < count(nums.begin(), nums.end(), cand2)) res.push_back(cand2);
        return res;
    }
};
