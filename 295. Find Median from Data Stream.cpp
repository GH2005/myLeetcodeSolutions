class MedianFinder
{
public:
    void addNum(int const num) noexcept
    {
        ++m_numToCount[num];
        
        if (std::get<1>(m_mid) == -1)
        {
            m_mid = { m_numToCount.begin(), 0 };
        }
        else
        {
            if (m_sizeIsOdd)
            {
                if (std::get<0>(m_mid)->first <= num)
                    this->increment(m_mid);
            }
            else
            {
                if (num < std::get<0>(m_mid)->first)
                    this->decrement(m_mid);
            }
        }
        
        m_sizeIsOdd = !m_sizeIsOdd;
    }
    
    double findMedian() const noexcept
    {
        if (std::get<1>(m_mid) == -1)
            return 0;
        if (m_sizeIsOdd)
        {
            return static_cast<double>(std::get<0>(m_mid)->first);
        }
        else
        {
            IndexType predecessor = m_mid;
            this->decrement(predecessor);
            return (
                    static_cast<double>(std::get<0>(m_mid)->first) +
                    static_cast<double>(std::get<0>(predecessor)->first)
                   )
                   / 2;
        }
    }
private:
    using MapType = std::map<int, ptrdiff_t>;
    using IndexType = std::tuple<MapType::iterator, ptrdiff_t>;
    
private:
    IndexType & decrement(IndexType & index) const noexcept
    {
        auto & [ iter, innerIndex ] = index;
        if (--innerIndex < 0)
        {
            --iter;
            innerIndex = iter->second - 1;
        }
        return index;
    }
    IndexType & increment(IndexType & index) const noexcept
    {
        auto & [ iter, innerIndex ] = index;
        if (iter->second <= ++innerIndex)
        {
            ++iter;
            innerIndex = 0;
        }
        return index;
    }
    
private:
    MapType m_numToCount;
    IndexType m_mid = { m_numToCount.end(), -1 };
    bool m_sizeIsOdd = false;
};
