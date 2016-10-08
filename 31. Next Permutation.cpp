class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // the edge case
        int count = nums.size();
        if (count == 0 && count == 1) return;
        
        // backward check
        int index = count - 2;
        while (index >= 0 && nums[index] >= nums[index+1]) index--;
        // index is now the position of the first smaller number or -1
        
        // exchange and reverse the order
        if (index >= 0) { // there is an exchange
            int index2 = count - 1;
            while (nums[index] >= nums[index2]) index2--;
            int temp = nums[index];
            nums[index] = nums[index2];
            nums[index2] = temp;
        }
        // reverse the order
        int left = index + 1;
        int right = count - 1;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left ++;
            right --;
        }
    }
};
