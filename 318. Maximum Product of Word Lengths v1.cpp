#define MAX_COUNT 1500
class Solution {
public:
    int maxProduct(vector<string>& words) {
        // response and edge input
        int res = 0;
        int count = words.size();
        /* debug */ printf("%d ", count);
        if (count == 0 || count == 1) return res;
        
        // hash tables
        bool word_ch_2Dhash[MAX_COUNT][26]; // 1 -- char exists
        memset(word_ch_2Dhash, 0, sizeof(bool)*MAX_COUNT*26);
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < words[i].size(); j++) word_ch_2Dhash[i][words[i][j] - 'a'] = true;
        }
        
        // enumerate pairs and update the response
        for (int i = 0; i < count - 1; i++) {
            for (int j = i+1; j < count; j++) {// words[i] and words[j]
                // sharing at least one char?
                bool shared = false;
                for (int k = 0; k < 26; k++) {
                    if (word_ch_2Dhash[i][k] & word_ch_2Dhash[j][k] != 0) {
                        shared = true;
                        break;
                    }
                }
                // if not sharing any char, compute the product
                if (!shared) {
                    int product = words[i].size() * words[j].size();
                    if (product > res) res = product;
                }
            }
        }
        
        // return
        return res;
    }
};
