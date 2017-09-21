class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int c = points.size();
        unordered_map<int, int> dist;
        int res = 0;
        for (int m = 0; m < c; m++)
        {
            dist.clear();
            for (int n = 0; n < c; n++)
            {
                if (n == m) continue;
                int distX = points[m].first - points[n].first;
                int distY = points[m].second - points[n].second;
                int distSquared = distX*distX + distY*distY;
                dist[distSquared]++;
            }
            for (auto it = dist.begin(); it != dist.end(); it++)
                res += it->second * (it->second - 1);
        }
        return res;
    }
};
