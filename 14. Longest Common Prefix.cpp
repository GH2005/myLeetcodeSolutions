class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) return "";
        
        string res;
        int dx = 0;
        while (1) {
            bool succ = true;
            char stdd = '\0';
            for (int i = 0; i < strs.size(); i++) {
                if (dx == strs[i].size()) { succ = false; break; }
                if (stdd == '\0') stdd = strs[0][dx];
                if (strs[i][dx] != stdd) { succ = false; break; }
            }
            if (succ) res += strs[0][dx];
            else break;
            dx++;
        }
        
        return res;
        
    }
};
