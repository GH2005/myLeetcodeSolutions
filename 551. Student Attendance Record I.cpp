class Solution {
public:
    bool checkRecord(string s) {
        bool absentOnce = false;
        int cContLate = 0;
        for (char c : s)
        {
            if (c == 'A')
                if (absentOnce) return false;
                else absentOnce = true;
            if (c != 'L') cContLate = 0;
            else if (++cContLate > 2) return false;
        }
        return true;
    }
};
