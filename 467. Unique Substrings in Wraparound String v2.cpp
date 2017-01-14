// with refence to one of the top solutions on LeetCode
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // preparations
        int contributions[26] = {};
        int currContri = 0;
        
        // one time pass dp
        for (int i = 0; i < p.size(); i++) {
            int letter = p[i] - 'a';
            // if the letter extends *currContri*
            if (i == 0 || letter != (p[i-1] - 'a' + 1) % 26) currContri = 1;
            else ++currContri;
            // if the letter gives more contributions than all previous occurances did
            if (currContri > contributions[letter]) contributions[letter] = currContri;
        }
        
        // return
        int res = 0;
        for (int i = 0; i < 26; i++) res += contributions[i];
        return res;
    }
};
