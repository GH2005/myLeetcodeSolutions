class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        if (height == 0) return 0;
        vector<int> lastSums(height, 0);
        for (int ceiling = height - 1; 0 <= ceiling; --ceiling) {
            int pos = height - 1 - ceiling;
            int lastSum = 0;
            for (int level = height - 1; ceiling <= level; --level) {
                if (level == height - 1) {
                    lastSum = lastSums[level];
                    lastSums[level] = triangle[level][pos];
                }
                else {
                    int sum = min(lastSum, lastSums[level+1]) + triangle[level][pos];
                    lastSum = lastSums[level];
                    lastSums[level] = sum;
                }
                --pos;
            }
        }
        return lastSums[0];
    }
};
