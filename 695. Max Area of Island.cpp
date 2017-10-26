class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        bool visited[50][50] = {};
        int m = grid.size(), n = grid[0].size();
        int fourDirects[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
        auto get_area = [&grid, &visited, &fourDirects, m, n](int y, int x)->int
        {
            queue<pair<int, int>> q;
            int area = 0;
            q.push(make_pair(y, x));
            visited[y][x] = true;
            while (!q.empty())
            {
                area++;
                int j = q.front().first, k = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int s = fourDirects[i][0] + j,
                        t = fourDirects[i][1] + k;
                    if (0 <= s && s < m && 0 <= t && t < n && !visited[s][t]
                       && grid[s][t] == 1)
                    {
                        visited[s][t] = true;
                        q.push(make_pair(s, t));
                    }
                }
            }
            return area;
        };
        for (int a = 0; a < m; a++)
        for (int b = 0; b < n; b++)
            if (grid[a][b] == 1 && !visited[a][b])
                maxArea = max(maxArea, get_area(a, b));
        return maxArea;
    }
};
