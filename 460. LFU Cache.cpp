class LFUCache
{
public:
    static constexpr int st_invalidValue = -1;
public:
    LFUCache(int const capacity) noexcept
      : m_capacity{capacity}
    {}
    
    int get(int const key) noexcept
    {
        if (m_capacity == 0)
            return st_invalidValue;
        
        auto const mapIt = m_map.find(key);
        if (mapIt == m_map.end())
            return st_invalidValue;
        HashElement & e = mapIt->second;
        
        LfuList::iterator const predecessorLfuIt = [this, &lfuIt = std::as_const(e.lfuIt)]() noexcept {
            if (lfuIt != m_lfuList.begin())
            {
                auto const beforeIt = --LfuList::iterator{lfuIt};
                if (beforeIt->frequency == lfuIt->frequency + 1)
                    return beforeIt;
            }
            return m_lfuList.emplace(lfuIt, lfuIt->frequency + 1);
        }();
        LruList & predLru = predecessorLfuIt->lruList;
        
        predLru.splice(predLru.cbegin(), e.lfuIt->lruList, e.lruIt);
        if (e.lfuIt->lruList.empty())
            m_lfuList.erase(e.lfuIt);
        
        e.lfuIt = predecessorLfuIt;
        e.lruIt = predLru.cbegin();
        return e.value;
    }
    
    void put(int const key, int const value) noexcept
    {
        if (m_capacity == 0)
            return;
        
        if (this->get(key) != st_invalidValue)
        {//it already exists
            m_map[key].value = value;
            return;
        }
        
        if (m_capacity <= m_length)
        {//removes the LFU and LRU one
            LruList & backLru = m_lfuList.back().lruList;
            m_map.erase(backLru.back());
            backLru.pop_back();
            if (backLru.empty())
                m_lfuList.pop_back();
            --m_length;
        }
        
        if (m_lfuList.empty() || 1 < m_lfuList.back().frequency)
            m_lfuList.emplace_back(1);
        m_lfuList.back().lruList.push_front(key);
        
        HashElement & e = m_map[key];
        e.lfuIt = --m_lfuList.end();
        e.lruIt = m_lfuList.back().lruList.cbegin();
        e.value = value;
        ++m_length;
    }
private:
    using LruList = std::list<int>;
    struct CoFrequencyGroup
    {
        CoFrequencyGroup(ptrdiff_t const i) noexcept : frequency{i} {}
        LruList lruList;
        ptrdiff_t const frequency;
    };
    using LfuList = std::list<CoFrequencyGroup>;
    struct HashElement
    {
        LfuList::iterator lfuIt;
        LruList::const_iterator lruIt;
        int value;
    };
    
    LfuList m_lfuList;
    std::unordered_map<int, HashElement> m_map;
    int const m_capacity;
    int m_length = 0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
