class Solution {
public:
    bool OK(int iS, int iP) {
        if (iS == cS) {
            // s passed.
            if (iP == cP) return true;
            else if (cP - iP < 2 || pp[iP + 1] != '*') return false;
            return OK(iS, iP + 2);
        }
        else {
            // remaining chs in s.
            if (iP == cP) return false;
            if (iP + 1 == cP) {
                if (pp[iP] != '.' && ss[iS] != pp[iP]) return false;
                return OK(iS + 1, iP + 1);
            }
            else {
                if (pp[iP + 1] != '*') return !(pp[iP] != '.' && ss[iS] != pp[iP]) && OK(iS + 1, iP + 1);

                if (OK(iS, iP + 2)) return true;
                if (pp[iP] == '.') {
                    for (int i = iS + 1; i <= cS; i++) {
                        if (OK(i, iP + 2)) return true;
                    }
                }
                else {
                    int i = iS + 1;
                    while (i <= cS && ss[i - 1] == pp[iP]) {
                        if (OK(i, iP + 2)) return true;
                        i++;
                    }
                }
                return false;
            }
        }
    }

    bool isMatch(string s, string p) {
    
        ss = s;
        pp = p;
        cS = s.size();
        cP = p.size();
        
        return OK(0, 0); 
        
    }
private:
    string ss;
    string pp;
    int cS;
    int cP;
};
