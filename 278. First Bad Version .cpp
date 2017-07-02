// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 0) return 0;
        int l = 1, r = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) r = m - 1;
            else l = m + 1;
        }
        return l <= n ? l : 0;
    }
};
