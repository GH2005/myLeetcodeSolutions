class Solution {
    vector<int> lastSums;
    vector<bool> open;
public:
    int minimumTotal(vector<vector<int>>& triangle, int level = 0, int pos = 0) {
        int height = triangle.size();
        if (level >= height) return 0;
        if (level == 0) {
            this->lastSums = vector<int>(height, 0);
            this->open = vector<bool>(height, false);
        }
        int value = triangle[level][pos];
        if (level == height - 1) { this->lastSums[level] = value; this->open[level] = true; return value; }
        // query the two below neighbors
        int sum = value;
        int sub = this->open[level+1] ? this->lastSums[level+1] : this->minimumTotal(triangle, level+1, pos);
        sum += min(sub, this->minimumTotal(triangle, level+1, pos+1) );
        this->open[level] = true;
        this->lastSums[level] = sum;
        return sum;
    }
};
