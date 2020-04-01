class MedianFinder
{
public:
    void addNum(int const num) noexcept
    {
        if (!m_num0)
        {
            m_num0.emplace(num);
            return;
        }
        if (m_leftHeap.size() == 0 && m_rightHeap.size() == 0)
        {
            if (m_num0.value() < num)
            {
                m_leftHeap.emplace(m_num0.value());
                m_rightHeap.emplace(num);
            }
            else
            {
                m_leftHeap.emplace(num);
                m_rightHeap.emplace(m_num0.value());
            }
            return;
        }
        
        if (num < m_leftHeap.top())
            m_leftHeap.emplace(num);
        else if (m_rightHeap.top() < num)
            m_rightHeap.emplace(num);
        else if (m_leftHeap.size() < m_rightHeap.size())
            m_leftHeap.emplace(num);
        else
            m_rightHeap.emplace(num);
        
        if (std::abs(static_cast<ptrdiff_t>(m_leftHeap.size()) - static_cast<ptrdiff_t>(m_rightHeap.size())) > 1)
        {
            if (m_leftHeap.size() < m_rightHeap.size())
            {
                m_leftHeap.emplace(m_rightHeap.top());
                m_rightHeap.pop();
            }
            else
            {
                m_rightHeap.emplace(m_leftHeap.top());
                m_leftHeap.pop();
            }
        }
    }
    
    double findMedian() const noexcept
    {
        if (!m_num0)
            return 0.0;
        if (m_leftHeap.size() == 0 && m_rightHeap.size() == 0)
            return static_cast<double>(m_num0.value());
        if (m_leftHeap.size() == m_rightHeap.size())
            return (static_cast<double>(m_leftHeap.top()) + static_cast<double>(m_rightHeap.top())) / 2;
        else if (m_leftHeap.size() < m_rightHeap.size())
            return static_cast<double>(m_rightHeap.top());
        else
            return static_cast<double>(m_leftHeap.top());
    }
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> m_leftHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_rightHeap;
    std::optional<int const> m_num0;
};
