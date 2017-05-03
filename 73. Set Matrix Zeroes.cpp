// based on the idea from mzchen
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = height > 0 ? matrix[0].size() : 0;
        if (height == 0 || width == 0) return;
        int row0 = matrix[0][0], col0 = matrix[0][0];
        for (int x = 0; x < width; x++) if (matrix[0][x] == 0) { row0 = 0; break; }
        for (int y = 0; y < height; y++) if (matrix[y][0] == 0) { col0 = 0; break; }
        for (int y = 1; y < height; y++)
            for (int x = 1; x < width; x++)
                if (matrix[y][x] == 0) { matrix[0][x] = matrix[y][0] = 0; }
        // set certain cells to 0 in range[1...height)[1...width)
        for (int y = 1; y < height; y++)
            for (int x = 1; x < width; x++)
                if (matrix[y][0] == 0 || matrix[0][x] == 0) matrix[y][x] = 0;
        // set certain cells to 0 in the first row and the first column
        if (col0 == 0) for (int y = 0; y < height; y++) matrix[y][0] = 0;
        if (row0 == 0) for (int x = 0; x < width; x++) matrix[0][x] = 0;
        return;
    }
};
