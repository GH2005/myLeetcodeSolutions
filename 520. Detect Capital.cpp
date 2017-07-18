class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        if (len == 1) return true;
        if ('a' <= word[0])
        {
            for (int pos = 1; pos < len; pos++)
                if (word[pos] < 'a')
                    return false;
            return true;
        }
        else
        {
            bool lc = 'a' <= word[1];
            for (int pos = 2; pos < len; pos++)
                if ( lc ? word[pos] < 'a' : 'a' <= word[pos] )
                    return false;
            return true;
        }
    }
};
