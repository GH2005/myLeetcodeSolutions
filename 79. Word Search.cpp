using CoorType = std::pair<ptrdiff_t, ptrdiff_t>;
CoorType & operator+=(CoorType & l, CoorType const & r) noexcept
{
    l.first += r.first;
    l.second += r.second;
    return l;
}

class Solution {
public:
    bool exist(std::vector<std::vector<char>> & board, std::string & word) noexcept {
        ptrdiff_t const wordSize =  word.size();
        if (wordSize == 0)
            return true;
        ptrdiff_t const boardHeight = board.size();
        if (boardHeight == 0)
            return false;
        ptrdiff_t const boardWidth = board[0].size();
        if (boardWidth == 0)
            return false;
        m_boardWidth = boardWidth;
        
        std::tuple<std::vector<std::vector<char>> &, std::string &> const info = { board, word };
        for (ptrdiff_t y = 0; y < boardHeight; ++y)
        {
            auto const & row = board[y];
            for (ptrdiff_t x = 0; x < boardWidth; ++x)
            {
                if (row[x] == word[0])
                {
                    CoorType const coor {x, y};
                    m_visited.clear(); m_visited.insert(coor);
                    if (this->Dfs(coor, 1, info))
                        return true;
                }
            }
        }

        return false;    
    }
private:
    ptrdiff_t m_boardWidth;
    std::function<std::size_t (CoorType const &)> const m_hash = [this](CoorType const & c) noexcept -> std::size_t
    {
        return c.first + c.second * this->m_boardWidth;
    };
    std::unordered_set<CoorType, decltype(m_hash)> m_visited { 10, m_hash };
    
    static constexpr inline CoorType st_momentum[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
    
    template<typename U>
    bool Dfs(CoorType const coor, ptrdiff_t const iword, U && info) noexcept
    {
        if (std::get<1>(info).size() <= iword)
            return true;
        for (int i = 0; i < 4; ++i)
        {
            CoorType newCoor = coor; newCoor += st_momentum[i];
            
            if (newCoor.first  < 0 || std::get<0>(info)[0].size() <= newCoor.first ||
                newCoor.second < 0 || std::get<0>(info).size()    <= newCoor.second)
                continue;
            if (std::get<0>(info)[newCoor.second][newCoor.first] != std::get<1>(info)[iword])
                continue;
            if (m_visited.count(newCoor) > 0)
                continue;
            
            m_visited.insert(newCoor);
            if (this->Dfs(newCoor, iword + 1, info))
                return true;
            m_visited.erase(newCoor);
        }
        return false;
    }    
};
