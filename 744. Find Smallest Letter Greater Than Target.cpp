class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        if (target < letters[0] || letters[len-1] <= target) return letters[0];
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return letters[left];
    }
};
