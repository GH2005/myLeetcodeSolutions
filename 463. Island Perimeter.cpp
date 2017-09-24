class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        auto contribute = [&grid](int y, int x)->int
        {
            int res = 0;
            if (x == 0 || grid[y][x-1] == 0) res++;
            if (x == grid[0].size() - 1 || grid[y][x+1] == 0) res++;
            if (y == 0 || grid[y-1][x] == 0) res++;
            if (y == grid.size() - 1 || grid[y+1][x] == 0) res++;
            return res;
        };
        for (int y = 0; y < grid.size(); y++)
        for (int x = 0; x < grid[0].size(); x++)
            if (grid[y][x] == 1) perimeter += contribute(y, x);
        return perimeter;
    }
};
