class Solution
{
public:
    static inline int constexpr st_infinity = std::numeric_limits<int>::max() / 2;
    
    int jump(std::vector<int> const & nums) const noexcept
    {
        if (nums.size() == 0)
            return st_infinity;
        
        std::vector<std::optional<int const>> minCountsOfJumpsFromPositions(nums.size());
        minCountsOfJumpsFromPositions.back().emplace(0);
        
        ptrdiff_t const initialPosition = 0;
        if (!minCountsOfJumpsFromPositions[initialPosition].has_value())
        {
            minCountsOfJumpsFromPositions[initialPosition].emplace(
                Solution::MinCountOfJumpsFromTheGivenPosition(initialPosition, nums, minCountsOfJumpsFromPositions)
            );
        }

        return minCountsOfJumpsFromPositions[initialPosition].value();
    }
    
private:
    static int MinCountOfJumpsFromTheGivenPosition(
        ptrdiff_t const position
      , std::vector<int> const & nums
      , std::vector<std::optional<int const>> & minCountsOfJumpsFromPositions
    )
    {
        if (nums.size() - 1 <= position + nums[position])
            return 1;
        
        int rtn = st_infinity;
        for (
            ptrdiff_t targetPosition = position + nums[position];
            position + 1 <= targetPosition;
            --targetPosition
            )
        {
            if (!minCountsOfJumpsFromPositions[targetPosition].has_value())
            {
                minCountsOfJumpsFromPositions[targetPosition].emplace(
                    Solution::MinCountOfJumpsFromTheGivenPosition(targetPosition, nums, minCountsOfJumpsFromPositions)
                );
            }
            rtn = std::min(rtn, 1 + minCountsOfJumpsFromPositions[targetPosition].value());
        }
        return rtn;
    }
};
