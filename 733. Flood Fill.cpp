class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        const int height = image.size(), width = image[0].size();
        // bfs
        const int movements[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
        const int oriColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (!q.empty())
        {
            int row = q.front().first, col = q.front().second; q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int movedRow = row + movements[dir][0];
                int movedCol = col + movements[dir][1];
                if (0 <= movedRow && movedRow < height &&
                    0 <= movedCol && movedCol < width &&
                    image[movedRow][movedCol] == oriColor)
                {
                    image[movedRow][movedCol] = newColor;
                    q.push(make_pair(movedRow, movedCol));
                }
            }
        }
        return image;
    }
};
