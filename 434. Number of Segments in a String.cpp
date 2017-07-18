class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        while (left < len && s[left] == ' ') left++;
        while (0 <= right && s[right] == ' ') right--;
        if (right < left) return 0;
        int res = 1;
        for (int pos = left; pos <= right; pos++)
            if (s[pos] == ' ' && s[pos-1] != ' ') res++;
        return res;
    }
};
