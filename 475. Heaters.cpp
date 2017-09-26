class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int cHouses = houses.size(), cHeaters = heaters.size();
        int res = INT_MIN;
        if (cHouses == 0) return 0;
        if (cHeaters == 0) return INT_MAX;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int iHouse = 0, iHeater = 0; iHouse < cHouses; iHouse++)
        {
            int leftDist = INT_MAX, rightDist = INT_MAX;
            // decide the nearest right heater for iHouse
            while (iHeater < cHeaters && heaters[iHeater] <= houses[iHouse])
                iHeater++;
            if (iHeater < cHeaters) rightDist = heaters[iHeater] - houses[iHouse];
            // the left heater
            iHeater--;
            if (iHeater >= 0) leftDist = houses[iHouse] - heaters[iHeater];
            // consider the nearer heater
            int dist = min(leftDist, rightDist);
            res = max(res, dist);
        }
        return res;
    }
};
