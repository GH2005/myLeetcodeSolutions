class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        int len = A.size();
        if (len < 1) return res;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        if (A[0]+B[0]+C[0]+D[0] > 0) return res;
        if (A[len-1]+B[len-1]+C[len-1]+D[len-1] < 0) return res;
        
        // exhaustive enumeration with trim
        int lenMOne = len - 1;
        for (int ia = 0; ia < len; ia++) {
            
            int va = A[ia];
            if (va+B[0]+C[0]+D[0] > 0) break;
            if (va+B[lenMOne]+C[lenMOne]+D[lenMOne] < 0) continue;
            for (int ib = 0; ib < len; ib++) {
                
                int vb = B[ib];
                if (va+vb+C[0]+D[0] > 0) break;
                if (va+vb+C[lenMOne]+D[lenMOne] < 0) continue;
                for (int ic = 0; ic < len; ic++) {
                    int vc = C[ic];
                    if (va+vb+vc+D[0] > 0) break;
                    if (va+vb+vc+D[lenMOne] < 0) continue;
                    for (int id = 0; id < len; id++) {
                        int sum = va + vb + vc + D[id];
                        if (sum < 0) continue;
                        else if (sum == 0) res ++;
                        else break;
                    }
                }
            }
        }
        
        return res;
    }
};
