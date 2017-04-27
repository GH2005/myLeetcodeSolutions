class Solution {
    int hashtable[26];
    inline int hash(char letter) { return letter - 'A'; }
    inline char get_most_frequent() {
        int wantedKey = 0;
        for (int key = 0; key < 26; key++) {
            if (this->hashtable[key] > this->hashtable[wantedKey])
                wantedKey = key;
        }
        return 'A' + wantedKey;
    }
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        s.push_back('A');
        int left = 0, right = 0;
        memset(this->hashtable, 0, sizeof(int) * 26);
        this->hashtable[this->hash(s[right])] ++;
        // move the window to the rightmost
        int width = 0;
        while (right < len) {
            // determine the number of required replacements
            char mode = this->get_most_frequent();
            // decide how to change the window
            if (right - left + 1 - this->hashtable[this->hash(mode)] > k) {
                -- this->hashtable[this->hash(s[left++])];
            }
            else width++;
            this->hashtable[this->hash(s[++right])] ++;
        }
        // return
        return width;
    }
};
