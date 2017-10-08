class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m * n;
        int minA = 40000, minB = 40000;
        for (vector<int> &op : ops)
        {
            minA = min(minA, op[0]);
            minB = min(minB, op[1]);
        }
        return minA * minB;
    }
};
