struct PP {
    PP(int inV, int inI) {
        this->v = inV;
        this->i = inI;
    }
    int v;
    int i;
};

bool lessThan(PP& p1, PP& p2) {
    return p1.v < p2.v ? true : false;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<PP> v;
        v.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(PP(nums[i], i + 1));
        }
        
        // sort.
        sort(v.begin(), v.end(), lessThan);
        
        // find it.
        int iFront = 0;
        int iRear = nums.size() - 1;
        vector<int> res;
        while (iFront < iRear) {
            int riFront = v[iFront].i;
            int riRear = v[iRear].i;
            if (v[iFront].v + v[iRear].v == target) {
                res.push_back(riFront < riRear ? riFront : riRear);
                res.push_back(riFront > riRear ? riFront : riRear);
                break;
            }
            else if (v[iFront].v + v[iRear].v > target) {
                iRear --;
            }
            else {
                iFront ++;
            }
        }
        return res;
        
    }
};
