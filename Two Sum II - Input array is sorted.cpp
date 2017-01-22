class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int len = numbers.size();
        int left = 0, right = len - 1;
        
        // search for it
        
        while(left < right) {
            int vLeft = numbers[left];
            int vRight = numbers[right];
            int sum = vLeft + vRight;
            if (sum < target) left++;
            else if (sum == target) break;
            else right--;
        }
        return vector<int>{left+1, right+1};
    }
};
