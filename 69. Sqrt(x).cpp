class Solution {
public:
    int mySqrt(int x) {
        int base = 0, delta = 1;
        for (int i = 1; i <= 46340; i++)
        {
            base += delta;
            delta += 2;
            if (x == base) return i;
            else if (x < base) return i - 1;
        }
        return 46340;
    }
};
