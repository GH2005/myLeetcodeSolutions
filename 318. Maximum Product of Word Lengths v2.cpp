#define MAX_COUNT 1500
class Solution {
public:
    int maxProduct(vector<string>& words) {
        // response and edge input
        int res = 0;
        int count = words.size();
        if (count == 0 || count == 1) return res;
        
        // hash tables
        int bitvec[MAX_COUNT]; // 1 -- char exists
        memset(bitvec, 0, sizeof(int)*count);
        for (int i = 0; i < count; i++) {// words[i]
            for (int j = 0; j < words[i].size(); j++) bitvec[i] |= 1 << (words[i][j] - 'a');
        }
        
        // enumerate pairs and update the response
        for (int i = 0; i < count - 1; i++) {
            for (int j = i+1; j < count; j++) {// words[i] and words[j]
                // if not sharing any char, compute the product
                if ((bitvec[i] & bitvec[j]) == 0) {
                    int product = words[i].size() * words[j].size();
                    if (product > res) res = product;
                }
            }
        }
        
        // return
        return res;
    }
};
