class Solution {
public:
    bool judgeSquareSum(int c) {
        int right = sqrt(c);
        int left = 0;
        while (left <= right)
        {
            int sum = right * right + left * left;
            if (sum < 0) break;
            int diff = sum - c;
            if (diff > 0) right--;
            else if (diff == 0) return true;
            else left++;
        }
        return false;
    }
};
