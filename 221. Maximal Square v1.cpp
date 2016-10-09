class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // preparation and the edge case
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        if (width == 0) return 0;
        
        // change chars into pure numbers
        for (int i=0; i < height; i++) {
            for (int j = 0; j < width; j++) matrix[i][j] -= '0';
        }
        
        // iterations
        int sideLenLimit = height > width? width : height;
        int res = 0;
        for (int sideLen = 1; sideLen <= sideLenLimit; sideLen++) {// a square of sideLen
            bool foundOne = false;
            for (int top = 0; top <= height - sideLen; top++) {// rectangle matrix[top..top+sideLen)[0...width)
                // compute the result of the AND operation
                if (sideLen != 1) {
                    for (int i = 0; i < width; i++) matrix[top][i] = matrix[top][i] & matrix[top+1][i];
                }
                // find how many consecutive '1's
                int cConsecOnes = 0;
                int theLongest = 0;
                for (int i = 0; i < width; i++) {// matrix[top][i]
                    char theNum = matrix[top][i];
                    if (theNum == 1) { cConsecOnes ++; if (cConsecOnes > theLongest) theLongest = cConsecOnes; }
                    else cConsecOnes = 0;
                }
                if (theLongest >= sideLen) foundOne = true;
            }
            if (!foundOne) break;
            else res = sideLen;
        }
        
        // return
        return res*res;
        
    }
};
