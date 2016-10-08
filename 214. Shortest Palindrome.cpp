class Solution {
public:
    string shortestPalindrome(string s) {
        // the response and an edge case
        string res;
        int oriSz = s.size();
        if (oriSz == 0) return res;
        res.reserve(2*oriSz);
        
        // stuffing
        string stuffedStr;
        int stuffedSz = 2*oriSz + 3;
        stuffedStr.reserve(stuffedSz);
        stuffedStr += '$';
        for (int i = 0; i < oriSz; i++) { // char s[i]
            stuffedStr += '#';
            stuffedStr += s[i];
        }
        stuffedStr += '#';
        stuffedStr += '^';
        
        //
        // Manacher's algorithm; customized
        //
        
        int *radii = new int[stuffedSz];
        radii[0] = 1;
        int globalPivot = 0;
        for (int currPivot = 1; currPivot < stuffedSz; currPivot++) {
            // calculate radii[currPivot]
            int& currRadius = radii[currPivot];
            int globalEnd = globalPivot + radii[globalPivot];   // exclusive
            if (currPivot < globalEnd) {
                int diff = globalEnd - currPivot;
                int radiusSymmPt = radii[2*globalPivot - currPivot];
                currRadius = diff < radiusSymmPt ? diff : radiusSymmPt;
            }
            else {
                currRadius = 1;
            }
            while (stuffedStr[currPivot-currRadius] == stuffedStr[currPivot+currRadius]) currRadius++;
            
            // update globalPivot
            int currEnd = currPivot + currRadius;   // exclusive
            if (currEnd > globalEnd) {
                globalPivot = currPivot;
            }
        }
        
        // go over radii[] and find the required window: longest and starting from 1
        int longestRadius = -1;
        int pivotWanted = -1;
        for (int i = 1; i < stuffedSz/2 + 1; i++) { // pivot i
            int stt = i - radii[i] + 1; // inclusive
            if (stt == 1) {
                if (radii[i] > longestRadius) {
                    longestRadius = radii[i];
                    pivotWanted = i;
                }
            }
        }
        
        // find the wanted palindrome substring in the original string s
        int iLast = radii[pivotWanted] - 2;
        // delete[] radii;
        
        // get the response
        for (int i = oriSz - 1; i > iLast; i--) { // char s[i]
            res += s[i];
        }
        res += s;
        return res;
    }
};
