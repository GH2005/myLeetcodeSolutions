class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // edge input cases
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        if (target == matrix[0][0] || target == matrix[m-1][n-1]) return true;
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        // phase 1: locate the row where target is possibly located in
        int mLeft = 0, mRight = m;
        int mSelected = -1;
        while (1) {// every iteration, every new range
            int mid = (mRight - mLeft) / 2 + mLeft;
            if (target < matrix[mid][0]) mRight = mid;
            else if (mid < mRight - 1 && target >= matrix[mid+1][0]) mLeft = mid + 1;
            else {
                mSelected = mid;
                break;
            }
        }
        
        // phase 2: decide whether target is existing
        int nLeft = 0, nRight = n;
        while (nLeft < nRight) {// every iteration, every new range
            int mid = (nRight - nLeft) / 2 + nLeft;
            if (target < matrix[mSelected][mid]) nRight = mid;
            else if (target > matrix[mSelected][mid]) nLeft = mid + 1;
            else return true;
        }
        return false;
    }
};
