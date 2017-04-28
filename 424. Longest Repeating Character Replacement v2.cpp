class Solution {
    int hashtable['Z' + 1];
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int left = 0, right = 0;
        memset(this->hashtable, 0, sizeof(int) * ('Z' + 1));
        char mode = 'A';
        while (right < len) {
            char newChar = s[right++];
            this->hashtable[newChar] ++;
            if (this->hashtable[mode] < this->hashtable[newChar]) mode = newChar;
            if (right - left - this->hashtable[mode] > k) {
                char droppedChar = s[left++];
                -- this->hashtable[droppedChar];
                if (droppedChar == mode)
                    mode = max_element(this->hashtable + 'A', this->hashtable + 'Z' + 1) - &this->hashtable['A'] + 'A';
            }
        }
        return right - left;
    }
};
