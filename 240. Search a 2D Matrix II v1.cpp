// 一言难尽
class Solution {
    int m_target = 0;
    const std::vector<std::vector<int>> *m_matrix = nullptr;
    bool prv_divideAndConquer(const std::pair<ptrdiff_t, ptrdiff_t> alpha,
                              const std::pair<ptrdiff_t, ptrdiff_t> beta)
    {
        if (alpha.first == beta.first) {
            ptrdiff_t left = alpha.second, right = beta.second;
            const ptrdiff_t first = alpha.first;
            while (left <= right) {
                const ptrdiff_t mid = left + (right - left) / 2;
                if (m_target <= (*m_matrix)[mid][first]) right = mid - 1;
                else left = mid + 1;
            }
            return left <= beta.second && (*m_matrix)[left][first] == m_target;
        }
        else if (alpha.second == beta.second) {
            ptrdiff_t left = beta.first, right = alpha.first;
            const ptrdiff_t second = beta.second;
            while (left <= right) {
                const ptrdiff_t mid = left + (right - left) / 2;
                if (m_target <= (*m_matrix)[second][mid]) right = mid - 1;
                else left = mid + 1;
            }
            return left <= alpha.first && (*m_matrix)[second][left] == m_target;
        }
        else {
            auto m = std::make_pair(beta.first, alpha.second);
            const ptrdiff_t sideDiff = std::min(beta.second - alpha.second, alpha.first - beta.first);
            const auto lowerRight = std::make_pair(m.first + sideDiff, m.second + sideDiff);
            auto n = lowerRight;
            while (m <= n) {
                const auto mid = std::make_pair(m.first + (n.first - m.first) / 2,
                                                m.second + (n.second - m.second) / 2);
                if (m_target <= (*m_matrix)[mid.second][mid.first]) {
                    n.first = mid.first - 1;
                    n.second = mid.second - 1;
                }
                else {
                    m.first = mid.first + 1;
                    m.second = mid.second + 1;
                }
            }
            if (n != lowerRight && (*m_matrix)[m.second][m.first] == m_target) return true;
            if (n.first < beta.first) return false;
            if (n.second < beta.second && prv_divideAndConquer(std::make_pair(n.first, m.second), beta)) {
                return true;
            }
            if (n.first < alpha.first && prv_divideAndConquer(alpha, std::make_pair(m.first, n.second))) {
                return true;
            }
            return false;
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t height = matrix.size();
        if (height == 0) return false;
        const size_t width = matrix[0].size();
        if (width == 0) return false;
        m_target = target;
        m_matrix = &matrix;
        return prv_divideAndConquer(std::make_pair(width-1, 0), std::make_pair(0, height-1));
    }
};
