class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        int validPoints[1000] = {}, cPoints = 0;
        for (string &op : ops)
        {
            int offset = 0;
            switch (op[0])
            {
                case '+':
                    offset = validPoints[cPoints-1] + validPoints[cPoints-2];
                    validPoints[cPoints++] = offset; break;
                case 'D':
                    offset = validPoints[cPoints-1] << 1;
                    validPoints[cPoints++] = offset; break;
                case 'C':
                    offset = -validPoints[--cPoints]; break;
                default:
                    offset = stoi(op);
                    validPoints[cPoints++] = offset;
            }
            sum += offset;
        }
        return sum;
    }
};
