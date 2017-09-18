class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxValues[3] = { INT_MIN, INT_MIN, INT_MIN };
        bool intMinExists = false;
        for (int target : nums)
        {
            if (target == INT_MIN) intMinExists = true;
            for (int i = 0; i < 3; i++)
            {
                if (maxValues[i] < target)
                    swap(maxValues[i], target);
                else if (maxValues[i] == target) break;
            }
        }
        if (maxValues[1] == INT_MIN || (!intMinExists && maxValues[2] == INT_MIN))
            return maxValues[0];
        else return maxValues[2];
    }
};
