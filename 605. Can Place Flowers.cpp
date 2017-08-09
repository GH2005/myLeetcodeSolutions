class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int len = flowerbed.size();
        if (len / 2 + 1 < n) return false;
        bool preceding = 0;
        int pos = 0;
        while (pos < len - 1)
        {
            if (flowerbed[pos] == 0 && preceding == 0
               && flowerbed[pos+1] == 0) n--, preceding = 1;
            else preceding = flowerbed[pos];
            pos++;
        }
        if (flowerbed[pos] == 0 && preceding == 0) n--;
        if (n <= 0) return true;
        else return false;
    }
};
