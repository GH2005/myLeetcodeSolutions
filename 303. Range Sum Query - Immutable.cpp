class NumArray {
    int len;
    vector<int> lookup;
public:
    NumArray(vector<int> nums) {
        
        this->len = nums.size();
        if (this->len == 0) return;
        
        // construct a lookup table
        
        this->lookup.reserve(this->len + 1);
        this->lookup.push_back(0);
        for (int i = 0; i < this->len; i++) this->lookup.push_back(this->lookup[i] + nums[i]);
        
    }
    
    int sumRange(int i, int j) {
        
        assert(i >= 0 && j < this->len);
        return this->lookup[j+1] - this->lookup[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
