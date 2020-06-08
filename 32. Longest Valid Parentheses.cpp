class Solution
{
public:
    int longestValidParentheses(std::string const & s) const noexcept
    {
        std::stack<int> positionsOfUnpairedOpeningParentheses;
        int lastPositionBeforeCurrentRange = -1;
        int maxLengthSoFar = 0;
        for (int pos = 0; pos < s.size(); ++pos)
        {
            if (s[pos] == '(')
            {
                positionsOfUnpairedOpeningParentheses.emplace(pos);
            }
            else
            {
                if (positionsOfUnpairedOpeningParentheses.empty())
                {
                    lastPositionBeforeCurrentRange = pos;
                }
                else
                {
                    positionsOfUnpairedOpeningParentheses.pop();
                    int const lastPositionBeforeTheClosedRange = 
                        positionsOfUnpairedOpeningParentheses.empty()
                      ? lastPositionBeforeCurrentRange
                      : positionsOfUnpairedOpeningParentheses.top();
                    maxLengthSoFar = std::max(maxLengthSoFar, pos - lastPositionBeforeTheClosedRange);
                }
            }
        }
        return maxLengthSoFar;
    }
};
