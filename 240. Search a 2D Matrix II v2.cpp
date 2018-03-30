// someone else's idea
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ptrdiff_t height = matrix.size();
        if (height == 0) return false;
        ptrdiff_t width = matrix[0].size();
        if (width == 0) return false;
        for (ptrdiff_t y = height - 1, x = 0; 0 <= y && x < width;) {
            if (target == matrix[y][x]) { return true; }
            target < matrix[y][x] ? --y : ++x;
        }
        return false;
    }
};
