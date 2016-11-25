#define MAX_SIZE 5000
class Solution {
private:
    struct Slice {
        int diff;
        bool isArith;
        Slice () :diff(0), isArith(0) {}
    };
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // edge cases
        int len = A.size();
        if (len < 3) return 0;
        
        // main process
        int res = 0;
        Solution::Slice dp[MAX_SIZE];
        // lenth 3: dp base
        for (int i = 0; i < len-2; i++) {// slice [i...i+2]
            int diff1 = A[i+1] - A[i];
            if (diff1 == A[i+2] - A[i+1]) {// an arithmetic 3-tuple
                dp[i].diff = diff1;
                dp[i].isArith = true;
                res ++;
            }
        }
        // from length 4 to len
        for (int currLen = 4; currLen <= len; currLen++) {
            for (int i = 0; i < len - currLen + 1; i++) {// slice A[i...i+currLen-1]: dp[i]
                // check if the slice is arithmetic
                bool itIs = true;
                if (!dp[i].isArith || !dp[i+1].isArith) itIs = false;
                else if (dp[i].diff != dp[i+1].diff) itIs = false;
                
                // update dp[i]
                if (!itIs) {
                    dp[i].isArith = false;
                }
                else {
                    res ++;
                }
            }
        }
        
        // return
        return res;
    }
};
