class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto it1 = nums.begin(), it2 = nums.end();
        make_heap(it1, it2);
        for (int i = 0; i < k; i++)
            pop_heap(it1, it2--);
        return *it2;
    }
};
