// moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0], c = 1;
        for (int pos = 1; pos < nums.size(); pos++)
        {
            if (c == 0) { curr = nums[pos]; c++; }
            else if (nums[pos] == curr) c++;
            else c--;
        }
        return curr;
    }
};
