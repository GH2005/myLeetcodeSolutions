class Solution {
public:
    bool isMatch(string s, string p) {
        
        s += '\0';
        p += '\0';
        int ip = 0, is = 0, starp = -1, iss = -1;
        
        while (s[is] != '\0') {
            if (p[ip] == s[is] || p[ip] == '?') { ip++; is++; continue; }
            if (p[ip] == '*') { starp = ++ip; iss = is; continue; }
            if (starp != -1) { ip = starp; is = iss++; continue; }
            return false;
        }
        
        while (p[ip] == '*') ip++;
        return p[ip] == '\0';
        
    }
};
