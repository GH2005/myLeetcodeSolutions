class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct Content
        {
            unsigned short posFirst, posLast, count;
            Content() :posFirst(UINT16_MAX), posLast(UINT16_MAX), count(0) {}
        };
        Content hashTable[50000];
        vector<unsigned short> maxCountEles;
        unsigned short maxCountSofar = 1;
        for (unsigned short pos = 0; pos < nums.size(); pos++)
        {// fill the hashTable, maxCountEles
            unsigned short v = nums[pos];
            Content &cont = hashTable[v];
            if (cont.posFirst == UINT16_MAX) // first met
                cont.posFirst = cont.posLast = pos;
            else cont.posLast = pos;
            cont.count++;
            if (cont.count < maxCountSofar) continue;
            if (cont.count > maxCountSofar) maxCountEles.clear(), maxCountSofar = cont.count;
            maxCountEles.push_back(v);
        }
        // find the smallest subarray length
        int minLen = UINT16_MAX;
        for (unsigned short ele : maxCountEles)
            minLen = min(minLen, hashTable[ele].posLast + 1 - hashTable[ele].posFirst);
        return minLen;
    }
};
