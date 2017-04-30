// luming89's solution

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) return matrix;
        int width = matrix[0].size();
        if (width == 0) return matrix;
        vector<vector<int>> res(height, vector<int>(width, 10000));
        // go over the matrix twice
        for (int times = 0; times < 2; times++) {
            for (int y = times ? 0 : height - 1; times ? (y < height) : (y >= 0); times ? y++ : --y) {
                for (int x = times ? 0 : width - 1; times ? (x < width) : (x >= 0); times ? x++ : --x) {
                    int value = matrix[y][x];
                    if (value == 0) res[y][x] = 0;
                    else {
                        // top
                        if (y > 0) res[y][x] = min(res[y][x], res[y-1][x] + 1);
                        // down
                        if (y < height - 1) res[y][x] = min(res[y][x], res[y+1][x] + 1);
                        // left
                        if (x > 0) res[y][x] = min(res[y][x], res[y][x-1] + 1);
                        // right
                        if (x < width - 1) res[y][x] = min(res[y][x], res[y][x+1] + 1);
                    }
                }
            }
        }
        return res;
    }
};
