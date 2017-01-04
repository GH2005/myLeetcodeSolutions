class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // preparations
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.reserve(numRows);
        
        // work on every row
        vector<int> row;
        row.reserve(numRows);
        row.push_back(1);
        res.push_back(row);
        for (int i = 1; i < numRows; i++) {// row i
            row.clear();
            row.push_back(1);
            for (int j = 1; j < i; j++) {
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        
        // job done
        return res;
    }
};
