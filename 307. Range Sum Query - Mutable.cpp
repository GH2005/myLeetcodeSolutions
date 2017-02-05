class NumArray {
    vector<int> segmentTree;
    int len = 0; 
public:
    NumArray(vector<int> nums) {
        this->len = nums.size();
        if (0 < this->len) {
            this->segmentTree.resize(this->len);
            this->segmentTree.insert(this->segmentTree.end(), nums.begin(), nums.end());
            for (int i = this->len - 1; 0 < i; i--)
                this->segmentTree[i] = this->segmentTree[2*i] + this->segmentTree[2*i + 1];
        }
    }
    
    void update(int i, int val) {
        i += this->len;
        int diff = val - this->segmentTree[i];
        while (0 < i) {
            this->segmentTree[i] += diff;
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        i += this->len, j += this->len;
        int sum = 0;
        while (i <= j) {
            if (i % 2 == 1) {
                sum += this->segmentTree[i];
                ++i;
            }
            if (j % 2 == 0) {
                sum += this->segmentTree[j];
                j--;
            }
            i /= 2, j /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
