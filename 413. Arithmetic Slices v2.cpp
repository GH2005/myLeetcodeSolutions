class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // edge cases
        int len = A.size();
        if (len < 3) return 0;
        
        // main process
        int res = 0;
        int accumulation = 0;
        for (int i = 0; i < len - 2; i++) {// new 3-tuple A[i...i+2]
            // if the 3-tuple is arithmetic, accumulation increases
            if (A[i+1] - A[i] == A[i+2] - A[i+1]) {// arithmetic
                accumulation++;
                res += accumulation;
            }
            else {// go back to zero
                accumulation = 0;
            }
        }
        
        // return
        return res;
    }
};
