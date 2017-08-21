class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while (0 <= end && s[end] == ' ') end--;
        if (end < 0) return 0;
        return end - s.rfind(' ', end);
    }
};
