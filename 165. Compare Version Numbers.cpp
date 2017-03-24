class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int start1 = 0, start2 = 0;
        // iteratively: ignore leading zeros, searching for dot, compare digits
        while (start1 < len1 || start2 < len2) {
            // ignore leading zeros
            while (start1 < len1 && version1[start1] == '0') start1++;
            while (start2 < len2 && version2[start2] == '0') start2++;
            // determine valid length
            int posDot1 = version1.find('.', start1);
            int c1 = posDot1 == -1 ? len1 - start1 : posDot1 - start1;
            int posDot2 = version2.find('.', start2);
            int c2 = posDot2 == -1 ? len2 - start2 : posDot2 - start2;
            if (c1 < c2) return -1;
            else if (c1 > c2) return 1;
            // compare digits
            for (int relativePos = 0; relativePos < c1; relativePos++) {
                int pos1 = start1 + relativePos, pos2 = start2 + relativePos;
                if (version1[pos1] < version2[pos2]) return -1;
                else if (version1[pos1] > version2[pos2]) return 1;
            }
            start1 += c1, start2 += c2;
            if (posDot1 != -1) start1++;
            if (posDot2 != -1) start2++;
        }
        return 0;
    }
};
