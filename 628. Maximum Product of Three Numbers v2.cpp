class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = min1, max1 = INT_MIN, max2 = max1, max3 = max1;
        for (int value : nums)
        {
            if (value < min1) { min2 = min1; min1 = value; }
            else if (value < min2) min2 = value;
            if (max3 < value) { max1 = max2; max2 = max3; max3 = value; }
            else if (max2 < value) { max1 = max2; max2 = value; }
            else if (max1 < value) max1 = value;
        }
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};
