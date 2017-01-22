class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        int len = A.size();
        if (len < 1) return res;
        
        // construct two unordered_maps containing sum of two numbers
        
        unordered_map<int, int> um1, um2;
        for (int iFirst = 0; iFirst < len; iFirst++) {
            for (int iSecond = 0; iSecond < len; iSecond++) {
                um1[A[iFirst] + B[iSecond]]++;
                um2[C[iFirst] + D[iSecond]]++;
            }
        }
        
        // search for quadruplets where sum == 0
        
        for (unordered_map<int, int>::iterator it1 = um1.begin();
            it1 != um1.end(); it1++) {
            
            int key1 = it1->first;
            int c1 = it1->second;
            unordered_map<int, int>::iterator it2 = um2.find(-key1);
            if (it2 != um2.end()) res += c1 * it2->second;
        }
        
        return res;
    }
};
