class Solution
{
public:
    int firstMissingPositive(std::vector<int> & nums) const noexcept
    {
        for (auto & num : nums)
            num = std::max(num, 0);
        nums.emplace_back(0);
        
        for (auto const num : nums)
        {
            for (auto value = num; 1 <= value && value < nums.size(); )
            {
                auto const nextValue = nums[value];
                nums[value] = st_numExistingTag;
                value = nextValue;
            }
        }
        
        int rtn = 1;
        while (rtn < nums.size())
        {
            if (nums[rtn] != st_numExistingTag)
                break;
            ++rtn;
        }
        return rtn;
    }
private:
    static inline int constexpr st_numExistingTag = -1;
};
