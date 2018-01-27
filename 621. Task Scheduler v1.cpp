// ONE OF THE MOST UGLY SOLUTION AND CODING STYLE I'VE EVER SHOWN

// APPARENTLY I'LL COMMIT A V2 NEXT WEEK

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        std::pair<char, int> hp[26] = {};
        for (int i = 0; i < 26; ++i) {
            hp[i].first = i + 'A';
        }
        for (char ch : tasks) {
            ++ hp[ch - 'A'].second;
        }
        auto pairCmp = [](const std::pair<char, int> &p1, const std::pair<char, int> &p2)->bool
        {
            return p1.second < p2.second;
        };
        ++n;
        std::make_heap(hp, hp + 26, pairCmp);
        int idleCount = 0;
        int intCount = 0;
        while (hp[0].second > 0) {
            idleCount = 0;
            std::queue<std::pair<char, int>> q;
            int hpLen = 26;
            for (int pos = 0; pos < n; ++ pos) {
                if (hpLen == 0 || hp[0].second == 0) {
                    ++ idleCount;
                }
                else {
                    std::pop_heap(hp, hp + hpLen, pairCmp);
                    q.push(hp[hpLen - 1]);
                    -- hpLen;
                }
                ++ intCount;
            }
            while (!q.empty()) {
                hp[hpLen++] = q.front();
                -- hp[hpLen-1].second;
                q.pop();
            }
            std::make_heap(hp, hp + 26, pairCmp);

        }
        intCount -= idleCount;
        return intCount;
    }
};
