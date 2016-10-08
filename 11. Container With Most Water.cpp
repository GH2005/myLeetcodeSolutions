class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1;
        int maxV = 0;
        
        while (right >= left + 1) {
            if (height[left] > height[right]) {
                int tmpV = (right - left) * height[right];
                maxV = tmpV > maxV ? tmpV : maxV;
                right --;
            }
            else {
                int tmpV = (right - left) * height[left];
                maxV = tmpV > maxV ? tmpV : maxV;
                left ++;
            }
        }
        
        return maxV;
        
    }
};
