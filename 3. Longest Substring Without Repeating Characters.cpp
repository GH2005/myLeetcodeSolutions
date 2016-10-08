class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int hash[256];
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        int start = -1;
        int end = 0;
        int res = 0;
        while (end < s.size()) {
            // set the window + modify hash.
            if (hash[s[end]] > -1) {
                // exists.
                for (int i = start + 1; i < hash[s[end]]; i++) {
                    hash[s[i]] = -1;
                }
                start = hash[s[end]];
            }
            hash[s[end]] = end;
            
            // compute length.
            res = res < (end - start) ? (end - start) : res;
            
            // UPDATE.
            end ++;
        }
        return res;
        
    }
};
