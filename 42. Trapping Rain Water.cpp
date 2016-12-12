class Solution {
public:
    int trap(vector<int>& height) {
        // edge input case: too few positions
        int sz = height.size();
        if (sz < 3) return 0;
        
        // decision of two border positions
        int left = -1, right = -1;
        int prev = -1;
        for (int i = 0; i < sz; i++) {
            if (height[i] < prev) {
                left = i - 1;
                break;
            }
            else prev = height[i];
        }
        prev = -1;
        for (int i = sz-1; i >= 0; i--) {
            if (height[i] < prev) {
                right = i + 1;
                break;
            }
            else prev = height[i];
        }
        if (left == -1 || right == -1 || right - left < 2) return 0;
        
        // initialize the water levels
        vector<int> waterLevels(height);
        bool leftIsHigher = height[left] > height[right] ? 1 : 0;
        int currLevel = 0;
        if (leftIsHigher) currLevel = height[right];
        else currLevel = height[left];
        for (int i = left + 1; i < right; i++) {
            if (currLevel > waterLevels[i]) waterLevels[i] = currLevel;
        }
        
        // iterations that update the water level for each position
        while (right - left >= 2) {
            // first higher wall or the highest wall among them
            int theHigher = -1;
            int maxHeightSoFar = -1, whereItIs = -1;
            if (leftIsHigher) {// left is higher
                for (int i = left + 1; i < right; i++) {
                    if (height[i] > maxHeightSoFar) {
                        maxHeightSoFar = height[i];
                        whereItIs = i;
                    }
                    if (height[i] > height[left]) {
                        theHigher = i;
                        break;
                    }
                }
                // update water levels and the border
                if (theHigher != -1) {
                    for (int i = left + 1; i < theHigher; i++) waterLevels[i] = height[left];
                    left = theHigher;
                }
                else {
                    if (maxHeightSoFar <= height[right]) break;
                    else {
                        for (int i = left + 1; i < whereItIs; i++) waterLevels[i] = height[whereItIs];
                        left = whereItIs;
                    }
                }
            }
            else {// the right border is higher
                for (int i = right - 1; i > left; i--) {
                    if (height[i] > maxHeightSoFar) {
                        maxHeightSoFar = height[i];
                        whereItIs = i;
                    }
                    if (height[i] > height[right]) {
                        theHigher = i;
                        break;
                    }
                }
                // update water levels and the border
                if (theHigher != -1) {
                    for (int i = right - 1; i > theHigher; i--) waterLevels[i] = height[right];
                    right = theHigher;
                }
                else {
                    if (maxHeightSoFar <= height[left]) break;
                    else {
                        for (int i = right - 1; i > whereItIs; i--) waterLevels[i] = height[whereItIs];
                        right = whereItIs;
                    }
                }
            }
        }
        
        // return the result
        int res = 0;
        for (int i = 0; i < sz; i++) res += waterLevels[i] - height[i];
        return res;
    }
};
