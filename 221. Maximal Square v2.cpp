#define WIDTH_LIMIT 200
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // preparation and the edge case
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        if (width == 0) return 0;
        int mxSideLenSF = 0;
        
        // the editorial solution - a single pass
        int dp[WIDTH_LIMIT];
        for (int i = 0; i < width; i++) {// first line
            dp[i] = matrix[0][i] - '0';
            if (dp[i] > mxSideLenSF) mxSideLenSF = dp[i];
        }
        for (int i = 1; i < height; i++) {// line matrix[i]
            int prev = dp[0];
            dp[0] = matrix[i][0] - '0';
            if (dp[0] > mxSideLenSF) mxSideLenSF = dp[0];
            for (int j = 1; j < width; j++) {// matrix[i][j] and dp[j]
                int dpValue = 0;
                if (matrix[i][j] == '1') {
                    int min = INT_MAX;
                    if (dp[j-1] < min) min = dp[j-1];
                    if (dp[j] < min) min = dp[j];
                    if (prev < min) min = prev;
                    dpValue = 1 + min;
                    if (dpValue > mxSideLenSF) mxSideLenSF = dpValue;
                }
                prev = dp[j];
                dp[j] = dpValue;
            }
        }
        
        
        // return
        return mxSideLenSF * mxSideLenSF;
        
    }
};
