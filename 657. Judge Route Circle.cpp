class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.size() == 0) return false;
        int y = 0, x = 0;
        for (char c : moves)
        {
            switch(c)
            {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++;
            }
        }
        return y == 0 && x == 0;
    }
};
