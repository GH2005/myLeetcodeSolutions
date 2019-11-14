class Solution {
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return {};
        
        std::unordered_map<char, int> keyChars;
        std::unordered_set<char>      unfulfilled;
        for (char const c: t)
        {
            ++keyChars[c];
            unfulfilled.insert(c);
        }
        
        std::string_view smallestWindow;
        ptrdiff_t smallestWindowSize = std::numeric_limits<ptrdiff_t>::max();
        
        std::string::const_pointer const last = s.data() + s.size();
        auto const keyEnd = keyChars.cend();
        for (std::string::const_pointer left = s.data(), right = left + 1; right <= last; ++right)
        {
            char const c = *(right - 1);
            if (auto const it = keyChars.find(c); it != keyEnd && --it->second == 0)
                unfulfilled.erase(c);
            
            while (left < right)
            {
                if (auto const it = keyChars.find(*left); it != keyEnd)
                {
                    if (0 <= it->second)
                        break;
                    ++it->second;
                }
                ++left;
            }
            
            if (ptrdiff_t const currSize = right - left; unfulfilled.empty() && currSize < smallestWindowSize)
            {
                smallestWindow = std::string_view {left, currSize};
                smallestWindowSize = currSize;
            }
        }
        
        return std::string{smallestWindow};
    }
};
