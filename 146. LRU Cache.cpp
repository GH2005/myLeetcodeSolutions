class LRUCache
{
public:
    LRUCache(int const capacity) noexcept
      : m_capacity(capacity)
    {
          
    }
    
    int get(int const key) noexcept
    {
        auto const findIt = m_iters.find(key);
        if (findIt == m_iters.end())
        {
            return -1;            
        }
        else
        {
            auto & it = findIt->second;
            int const value = it->second;
            m_values.erase(it);
            it = m_values.emplace(m_values.begin(), key, value);
            return value;
        }
    }
    
    void put(int const key, int const value) noexcept
    {
        if (auto const findIt = m_iters.find(key); findIt != m_iters.end())
            m_values.erase(findIt->second);
        m_iters[key] = m_values.emplace(m_values.begin(), key, value);
        if (m_capacity < m_iters.size())
        {
            m_iters.erase(m_values.back().first);
            m_values.pop_back();
        }
    }
private:
    std::list<std::pair<int, int>> m_values;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_iters;
    int const m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
