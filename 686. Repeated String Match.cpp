class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lenA = A.size(), lenB = B.size();
        for (int start = 0; start < lenA; start++)
        {
            int cRepeating = start == 0 ? 0 : 1;
            for (int posA = start, posB = 0; posB < lenB; posA++, posA %= lenA, posB++)
            {
                if (posA == 0) cRepeating++;
                if (A[posA] != B[posB]) goto notMatched;
            }
            return cRepeating;
            notMatched:;
        }
        return -1;
    }
};
