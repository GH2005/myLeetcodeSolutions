class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 4) return 1;
        if (x < 9) return 2;
        int left = 3, right = min(x / 3, 46340);
        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (x <= mid * mid) right = mid - 1;
            else left = mid + 1;
        }
        if (left * left == x) return left;
        else return right;
    }
};
