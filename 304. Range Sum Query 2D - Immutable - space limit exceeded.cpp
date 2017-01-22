class NumMatrix {
private:
    int m;
    int n;
    vector<vector<int>> lookup; // lookup[lowerRight linear][upperLeft linear]
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        
        this->m = matrix.size();
        if (this->m == 0) return;
        this->n = matrix[0].size();
        if (this->n == 0) return;
        
        // construct a lookup table
        int linearLen = this->m * this->n;
        this->lookup.reserve(linearLen);
        for (int r2 = 0; r2 < this->m; r2++) {
            for (int c2 = 0; c2 < this->n; c2++) {// all rectangles ending at (r2, c2)
                int linearIndex2 = r2 * this->n + c2;
                vector<int> lookupRow(linearLen);
                for (int r1 = 0; r1 <= r2; r1++) {
                    for (int c1 = 0; c1 <= c2; c1++) {
                        int linearIndex1 = r1 * this->n + c1;
                        if (r1 == r2 && c1 == c2) lookupRow[linearIndex1] = matrix[r2][c2];
                        else if (r1 == r2) lookupRow[linearIndex1] = this->lookup[linearIndex2-1][linearIndex1] + matrix[r2][c2];
                        else if (c1 == c2) lookupRow[linearIndex1] = this->lookup[linearIndex2 - this->n][linearIndex1] + matrix[r2][c2];
                        else lookupRow[linearIndex1] = this->lookup[linearIndex2-1][linearIndex1]
                                + this->lookup[linearIndex2 - this->n][linearIndex1] + matrix[r2][c2]
                                - this->lookup[linearIndex2 - this->n - 1][linearIndex1];
                    }
                }
                this->lookup.push_back(lookupRow);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        assert(row1 >= 0 && row2 < this->m);
        assert(col1 >= 0 && col2 < this->n);
        return this->lookup[row2 * this->n + col2][row1 * this->n + col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
