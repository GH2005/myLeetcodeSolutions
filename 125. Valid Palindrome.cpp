class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            char &leftCh = s[left], &rightCh = s[right];
            if ('A' <= leftCh && leftCh <= 'Z') leftCh += 'a' - 'A';
            else if ( !('a' <= leftCh && leftCh <= 'z') && !('0' <= leftCh && leftCh <= '9') )
                { left++; continue; }
            if ('A' <= rightCh && rightCh <= 'Z') rightCh += 'a' - 'A';
            else if ( !('a' <= rightCh && rightCh <= 'z') && !('0' <= rightCh && rightCh <= '9') )
                { right--; continue; }
            if (leftCh != rightCh) return false;
            else left++, right--;
        }
        return true;
    }
};
