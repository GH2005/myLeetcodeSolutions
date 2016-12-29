class Solution {
public:
    int strongPasswordChecker(string s) {
        // cases where insertions are required
        int sz = s.size();
        if (sz < 5) return 6 - sz;
        if (sz == 5) {// the only special case
            // go over the string and extract useful info
            bool lcExist = false, ucExist = false, digiExist = false;
            bool allSame = true;
            char prevCh = s[0];
            for (int i = 0; i < 5; i++) {
                if (!lcExist && s[i] >= 'a' && s[i] <= 'z') lcExist = true;
                if (!ucExist && s[i] >= 'A' && s[i] <= 'Z') ucExist = true;
                if (!digiExist && s[i] >= '0' && s[i] <= '9') digiExist = true;
                if (s[i] != prevCh) allSame = false;
                prevCh = s[i];
            }
            // decisions will be made based on the info
            int cC2Requires = !lcExist + !ucExist + !digiExist;
            assert(cC2Requires != 3);
            if (cC2Requires == 2) return 2; // one insertion and one replacement: sufficient
            else {// the one insertion can meet C2
                if (allSame) return 2;
                else return 1;
            }
        }
        
        int res = 0;
        
        // go over the string and extract useful info
        bool lcExist = false, ucExist = false, digiExist = false;
        char prevCh = s[0];
        int cRepetition = 0;
        vector<int> repeatingGroups;
        for (int i = 0; i < sz; i++) {
            if (!lcExist && s[i] >= 'a' && s[i] <= 'z') lcExist = true;
            if (!ucExist && s[i] >= 'A' && s[i] <= 'Z') ucExist = true;
            if (!digiExist && s[i] >= '0' && s[i] <= '9') digiExist = true;
            if (s[i] == prevCh) {
                cRepetition ++;
            }
            else {
                if (cRepetition >= 3) repeatingGroups.push_back(cRepetition);
                cRepetition = 1;
            }
            prevCh = s[i];
        }
        if (cRepetition >= 3) repeatingGroups.push_back(cRepetition);
        int cGroups = repeatingGroups.size();
        /*debug*/ for(int i = 0; i < cGroups; i++) printf(" %d", repeatingGroups[i]);
        printf("\n");
        int cC2Requires = !lcExist + !ucExist + !digiExist; // these requirements cannot be met by deletions
        
        // deletions are required if *sz* > 20, which shouldn't influence C2
        if (sz > 20) {
            int cDelRequired = sz - 20;
            res += cDelRequired;
            // see how many replacements are saved by deletions
            for (int iDel = 0; iDel < cDelRequired; iDel++) {// for every mandatory deletion, exploit it to the most
                int iGroup = 0;
                while (iGroup < cGroups && (repeatingGroups[iGroup] % 3 != 0 || repeatingGroups[iGroup] < 3)) iGroup ++;
                if (iGroup < cGroups) {// a rank 1 group is found
                    repeatingGroups[iGroup] --; // it becomes a rank 3 group
                }
                else {
                    // try to find a rank 2 group
                    iGroup = 0;
                    while (iGroup < cGroups && (repeatingGroups[iGroup] % 3 != 1 || repeatingGroups[iGroup] < 3)) iGroup ++;
                    if (iGroup < cGroups) {// rank 2 group found
                        repeatingGroups[iGroup] --; // it becomes a rank 1 group
                    }
                    else {
                        iGroup = 0;
                        while (iGroup < cGroups && (repeatingGroups[iGroup] % 3 != 2 || repeatingGroups[iGroup] < 3)) iGroup ++;
                        if (iGroup < cGroups) {// rank 3 group found
                            repeatingGroups[iGroup] -- ; // it becomes a rank 2 group
                        }
                        else break;
                    }
                }
            }
        }
        
        // if there is still a need for replacements, do it now
        int replacementsForSplitting = 0;
        for (int i = 0; i < cGroups; i++) replacementsForSplitting += repeatingGroups[i] / 3;
        int cReplacements = cC2Requires > replacementsForSplitting ? cC2Requires : replacementsForSplitting;
        
        // return
        res += cReplacements;
        return res;
    }
};
