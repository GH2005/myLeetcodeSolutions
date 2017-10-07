class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size() / 2;
        sort(candies.begin(), candies.end());
        int cKinds = 1;
        for (int pos = 1; pos < candies.size(); pos++)
            if (candies[pos - 1] != candies[pos]) cKinds++;
        if (cKinds >= n) return n;
        else return cKinds;
    }
};
