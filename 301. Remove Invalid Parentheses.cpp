//editorial solution
class Solution {
  std::string m_stk;
  std::unordered_set<std::string> m_uniqueResults;
  ptrdiff_t m_len = 0;
  std::string const *m_s = nullptr;
private:
  void prv_bt(ptrdiff_t const i,
              ptrdiff_t const outstandingLefts,
              ptrdiff_t const leftToRemove,
              ptrdiff_t const rightToRemove) noexcept {
    if (i >= m_len) {
      if (outstandingLefts == 0 && leftToRemove == 0 && rightToRemove == 0) {
        m_uniqueResults.insert(m_stk);
      }
      return;
    }
    
    char const c = (*m_s)[i];
    switch (c) {
      case '(': {
        if (leftToRemove > 0) {
          prv_bt(i+1, outstandingLefts, leftToRemove - 1, rightToRemove);
        }
        m_stk += c;
        prv_bt(i+1, outstandingLefts + 1, leftToRemove, rightToRemove);
        m_stk.pop_back();
        break;
      }
      case ')': {
        if (rightToRemove > 0) {
          prv_bt(i+1, outstandingLefts, leftToRemove, rightToRemove - 1);
        }
        if (outstandingLefts == 0) { break; }
        m_stk += c;
        prv_bt(i+1, outstandingLefts - 1, leftToRemove, rightToRemove);
        m_stk.pop_back();
        break;
      }
      default: {
        //any other char is considered
        m_stk += c;
        prv_bt(i+1, outstandingLefts, leftToRemove, rightToRemove);
        m_stk.pop_back();
      }
    }
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    m_len = s.size();
    m_stk.clear();
    m_uniqueResults.clear();
    m_s = &s;
    
    //decide # of parentheses to be removed
    ptrdiff_t leftToRemove = 0, rightToRemove = 0;
    for (char const c : s) {
      switch (c) {
        case '(': {
          ++leftToRemove;
          break;
        }
        case ')': {
          if (leftToRemove == 0) {
            ++rightToRemove;
          }
          else {
            --leftToRemove;
          }
          break;
        }
        default: {
          ;
        }
      }
    }
    
    prv_bt(0, 0, leftToRemove, rightToRemove);
    return std::vector<std::string>(m_uniqueResults.cbegin(), m_uniqueResults.cend());
  }
};
