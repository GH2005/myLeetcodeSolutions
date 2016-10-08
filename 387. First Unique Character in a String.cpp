class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        int sz = s.size();
        
        // go over string and get counts
        int count[26] = {};
        for (int i = 0; i < sz; i++) count[s[i]-'a']++;
        
        // decide res
        for (int i = 0; i < sz; i++)
            if (count[s[i]-'a'] == 1) {
                res = i;
                break;
            }
        
        // return
        return res;
    }
};
