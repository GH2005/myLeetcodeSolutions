class Solution {
    vector<int> vec;
public:
    Solution(vector<int> nums) {
        this->vec = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = this->vec;
        int len = res.size();
        // shuffle it
        for (int base = 0; base < len - 1; base++) {
            int tgt = base + rand() % (len - base);
            if (base < tgt) swap(res[base], res[tgt]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
