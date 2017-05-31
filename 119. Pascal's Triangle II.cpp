class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 2) return vector<int>(rowIndex+1, 1);
        vector<int> v1(rowIndex+1, 1), v2(rowIndex+1, 1);
        vector<int> *aVa = &v1, *aVb = &v2;
        for (int row = 2; row <= rowIndex; row++)
        {
            for (int pos = 1; pos < row; pos++)
                (*aVa)[pos] = (*aVb)[pos-1] + (*aVb)[pos];
            swap(aVa, aVb);
        }
        return (*aVb);
    }
};
