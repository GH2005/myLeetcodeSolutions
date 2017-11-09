class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // assume that bits are always valid and decodable
        bool lastDecoded = true; // true - one-bit; false - two-bit
        for (int pos = 0; pos < bits.size(); pos++)
            if (bits[pos] == 0) lastDecoded = true;
            else lastDecoded = false, pos++;
        return lastDecoded;
    }
};
