class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        using SizeType = vector<vector<int>>::size_type;
        using DiffType = vector<vector<int>>::difference_type;
        SizeType sideLen = matrix.size();
        if (sideLen <= 1) return;
        if (sideLen != matrix[0].size()) return;
        const std::array<std::array<DiffType, 2>, 4> roundShifts = { 1, 0, 0, 1, -1, 0, 0, -1 };
        const std::array<std::array<DiffType, 2>, 4> inwardShifts = { 1, 1, -1, 1, -1, -1, 1, -1 };
        std::array<std::array<SizeType, 2>, 4> initialPositions = {
            0, 0,
            sideLen-1, 0,
            sideLen-1, sideLen-1,
            0, sideLen-1
        };
        for (DiffType shiftGroupLen = sideLen - 1; 0 < shiftGroupLen; shiftGroupLen -= 2) {
            auto currPositions = initialPositions;
            for (DiffType shiftSeq = 0; shiftSeq < shiftGroupLen; ++shiftSeq) {
                int temp = 0;
                for (DiffType i = 0; i < 4; ++i) {
                    swap(temp, matrix[currPositions[i][1]][currPositions[i][0]]);
                }
                swap(temp, matrix[currPositions[0][1]][currPositions[0][0]]);
                for (DiffType i = 0; i < 4; ++i) {
                    currPositions[i][0] += roundShifts[i][0];
                    currPositions[i][1] += roundShifts[i][1];
                }
            }
            for (DiffType i = 0; i < 4; ++i) {
                initialPositions[i][0] += inwardShifts[i][0];
                initialPositions[i][1] += inwardShifts[i][1];
            }
        }
        return;
    }
};
