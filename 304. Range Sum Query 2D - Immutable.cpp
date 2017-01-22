class NumMatrix {
private:
    int m;
    int n;
    vector<vector<int>> lookup; // (this->m + 1) times (this->n + 1)
    
public:
    NumMatrix(vector<vector<int>> &&matrix) {
        
        this->m = matrix.size();
        if (this->m == 0) return;
        this->n = matrix[0].size();
        if (this->n == 0) return;
        
        // construct a lookup table
        this->lookup = vector<vector<int>>(this->m + 1, vector<int>(this->n + 1, 0));
        for (int r2 = 1; r2 <= this->m; r2++) {
            for (int c2 = 1; c2 <= this->n; c2++) {// (r2, c2) in this->lookup, corresponding number matrix[r2-1][c2-1]
                int num = matrix[r2 - 1][c2 - 1];
                this->lookup[r2][c2] = this->lookup[r2][c2 - 1] + this->lookup[r2 - 1][c2] - this->lookup[r2 - 1][c2 - 1] + num;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        assert(row1 >= 0 && row2 < this->m);
        assert(col1 >= 0 && col2 < this->n);
        
        // interpretation
        
        int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;
        
        // return
        return this->lookup[r2][c2] - this->lookup[r2][c1 - 1] - this->lookup[r1 - 1][c2] + this->lookup[r1 - 1][c1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
