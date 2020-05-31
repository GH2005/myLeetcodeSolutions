class Solution
{
public:
    static inline int constexpr st_infinity = std::numeric_limits<int>::max() / 2;
    
    int jump(std::vector<int> const & nums) const noexcept
    {
        if (nums.size() == 0)
            return st_infinity;
        
        std::vector<int> minCountsOfJumps(nums.size(), st_infinity);
        minCountsOfJumps.back() = 0;
        for (ptrdiff_t numIndex = nums.size() - 2; 0 <= numIndex; --numIndex)
        {
            if (nums.size() - 1 <= numIndex + nums[numIndex])
            {
                minCountsOfJumps[numIndex] = 1;
                continue;
            }
            
            for (
                ptrdiff_t jumpTargetIndex = numIndex + 1;
                jumpTargetIndex <= numIndex + nums[numIndex];
                ++jumpTargetIndex
                )
            {
                minCountsOfJumps[numIndex] = std::min(minCountsOfJumps[numIndex], 1 + minCountsOfJumps[jumpTargetIndex]);
                if (minCountsOfJumps[numIndex] == 2)
                    break;
            }
        }
        
        return minCountsOfJumps.front();
    }
};
