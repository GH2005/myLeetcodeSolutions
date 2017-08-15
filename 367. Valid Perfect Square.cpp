class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1 || num == 4 || num == 9)
            return true;
        if (num <= 10) return false;
        int left = 1, right = min(num / 3, 46340);
        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (num <= mid * mid) right = mid - 1;
            else left = mid + 1;
        }
        return left * left == num;
    }
};
