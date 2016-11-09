class Solution {
private:
    vector<int> *pList;
    int res;
    bool binary_search(int start, int end/*exclusive*/) {
        // return the first or the last item
        // base cases
        // /*debug*/ printf("range %d - %d\n", start, end);
        if (end - start == 1) return false;
        
        // lengh >= 2
        vector<int>& list = *(this->pList);
        if (list[start] >= list[end-1]) {// division is needed
            int len = end - start;
            int mid = start + len / 2;
            if (list[mid-1] > list[mid]) {
                this->res = list[mid];
                return true;
            }
            else {
                return binary_search(start, mid) || binary_search(mid, end);
            }
        }
        else return false;
    }
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        
        // search for the gap
        this->res = nums[0];
        this->pList = &nums;
        binary_search(0, len);
        
        // return
        return this->res;
    }
};
