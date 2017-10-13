class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == s[right]) left++, right--;
        if (right <= left) return true;
        int l = left + 1, r = right;
        while (l < r && s[l] == s[r]) l++, r--;
        if (r <= l) return true;
        l = left, r = right - 1;
        while (l < r && s[l] == s[r]) l++, r--;
        if (r <= l) return true;
        return false;
    }
};
