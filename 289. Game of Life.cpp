// idea by Stefan Pochmann
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int height = board.size(), width = height > 0 ? board[0].size() : 0;
        if (height == 0 || width == 0) return;
        // update the state using the second bit
        for (int centerY = 0; centerY < height; centerY++)
            for (int centerX = 0; centerX < width; centerX++) {
                int count = - board[centerY][centerX];
                for (int y = max(0, centerY-1); y < min(height, centerY+2); y++)
                    for (int x = max(0, centerX-1); x < min(width, centerX+2); x++)
                        count += board[y][x] & 1;
                if ((count | board[centerY][centerX]) == 3)
                    board[centerY][centerX] |= 2;
            }
        // right shift to let the new state take effect
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                board[y][x] >>= 1;
        return;
    }
};
