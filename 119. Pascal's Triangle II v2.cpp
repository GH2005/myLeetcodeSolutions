class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int row = 0; row <= rowIndex; row++)
            for (int pos = row-1; 1 <= pos; pos--)
                res[pos] = res[pos] + res[pos-1];
        return res;
    }
};
