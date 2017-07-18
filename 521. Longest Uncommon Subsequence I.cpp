class Solution {
public:
    int findLUSlength(string a, string b) {
        int lenA = a.size(), lenB = b.size();
        if (lenA != lenB) return max(lenA, lenB);
        if (a != b) return lenA;
        return -1;
    }
};
