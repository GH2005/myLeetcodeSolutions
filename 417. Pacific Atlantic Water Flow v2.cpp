class Solution {
    struct Result {
        bool toPacific;
        bool toAtlantic;
        Result(bool a, bool b) :toPacific(a), toAtlantic(b) {}
        Result() : toPacific(false), toAtlantic(false) {}
    };
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // initialization of the response object
        vector<pair<int, int>> res;
        
        // edge input cases
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        if (m == 1) {
            for (int x = 0; x < n; x++) res.push_back(pair<int, int>(0, x));
            return res;
        }
        if (n == 1) {
            for (int y = 0; y < m; y++) res.push_back(pair<int, int>(y, 0));
            return res;
        }
        
        // results
        Result results[150][150];
        
        // for easier movements
        int moveY[4] = { -1, 0, 1, 0 };
        int moveX[4] = { 0, 1, 0, -1 };
        
        // bfs
        // bool visited[150][150];
        queue<pair<int, int>> q;
        for (int x = 0; x < n; x++) {// the cells along the upper and lower border
            // the upper cell
            // memset(visited, 0, 150*150*sizeof(bool));
            q.push(pair<int, int>(0, x));
            // visited[0][x] = true;
            results[0][x].toPacific = true;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newY = p.first + moveY[i];
                    int newX = p.second + moveX[i];
                    // if it conforms to restrictions, consider it
                    if (newY >= 0 && newY < m && newX >= 0 && newX < n
                        && !results[newY][newX].toPacific
                        && matrix[newY][newX] >= matrix[p.first][p.second]) {
                            
                        q.push(pair<int, int>(newY, newX));
                        results[newY][newX].toPacific = true;
                    }
                }
            }
            // the lower cell
            // memset(visited, 0, 150*150*sizeof(bool));
            q.push(pair<int, int>(m-1, x));
            // visited[m-1][x] = true;
            results[m-1][x].toAtlantic = true;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newY = p.first + moveY[i];
                    int newX = p.second + moveX[i];
                    // if it conforms to restrictions, consider it
                    if (newY >= 0 && newY < m && newX >= 0 && newX < n
                        && !results[newY][newX].toAtlantic
                        && matrix[newY][newX] >= matrix[p.first][p.second]) {
                            
                        q.push(pair<int, int>(newY, newX));
                        results[newY][newX].toAtlantic = true;
                    }
                }
            }
        }
        for (int y = 0; y < m; y++) {// cells along the left and right border
            // the left cell
            // memset(visited, 0, 150*150*sizeof(bool));
            q.push(pair<int, int>(y, 0));
            // visited[0][x] = true;
            results[y][0].toPacific = true;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newY = p.first + moveY[i];
                    int newX = p.second + moveX[i];
                    // if it conforms to restrictions, consider it
                    if (newY >= 0 && newY < m && newX >= 0 && newX < n
                        && !results[newY][newX].toPacific
                        && matrix[newY][newX] >= matrix[p.first][p.second]) {
                            
                        q.push(pair<int, int>(newY, newX));
                        results[newY][newX].toPacific = true;
                    }
                }
            }
            // the right cell
            // memset(visited, 0, 150*150*sizeof(bool));
            q.push(pair<int, int>(y, n-1));
            // visited[m-1][x] = true;
            results[y][n-1].toAtlantic = true;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newY = p.first + moveY[i];
                    int newX = p.second + moveX[i];
                    // if it conforms to restrictions, consider it
                    if (newY >= 0 && newY < m && newX >= 0 && newX < n
                        && !results[newY][newX].toAtlantic
                        && matrix[newY][newX] >= matrix[p.first][p.second]) {
                            
                        q.push(pair<int, int>(newY, newX));
                        results[newY][newX].toAtlantic = true;
                    }
                }
            }
        }
        
        // examine *results* and complete the response
        for (int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {// cell[y][x]
                Result& theResult = results[y][x];
                if (theResult.toPacific && theResult.toAtlantic)
                    res.push_back(pair<int, int>(y, x));
            }
        }
        return res;
    }
};
