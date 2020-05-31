class Solution
{
public:
    int jump(std::vector<int> const & nums) const noexcept
    {
        if (nums.size() == 0)
            return std::numeric_limits<int>::max();
        if (nums.size() == 1)
            return 0;
        
        std::pair<int, int> currentRange { 0, 0 };
        for (int stepCount = 1; ; ++stepCount)
        {
            int farthestReachablePositionSoFar = currentRange.second;
            for (int pos = currentRange.first; pos <= currentRange.second; ++pos)
            {
                farthestReachablePositionSoFar = std::max(farthestReachablePositionSoFar, pos + nums[pos]);
                if (nums.size() - 1 <= farthestReachablePositionSoFar)
                    return stepCount;
            }
            currentRange = { currentRange.second + 1, farthestReachablePositionSoFar };
        }
    }
};
