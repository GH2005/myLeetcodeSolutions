class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		if (n == 0) return tasks.size();
		++n;
		std::array<size_t, 26> hashTbl{};
		for (char ch : tasks) {
			++ hashTbl[ch - 'A'];
		}
		std::array<unsigned int, 26> heap;
		auto bgnIt = heap.begin(), endIt = heap.end();
		std::iota(bgnIt, endIt, 0);
		auto cmp = [&hashTbl](const unsigned int &lhs, const unsigned int &rhs)->bool {
			return hashTbl[lhs] < hashTbl[rhs];
		};
		int cmdCnt, rndCnt = 0;
		std::make_heap(bgnIt, endIt, cmp);
		while (hashTbl[heap[0]] > 0)
		{
			++rndCnt;
			cmdCnt = 0;
			size_t heapLen = 26;
			for (size_t pos = 0; pos < n; ++pos) {
				if (heapLen == 0 || hashTbl[heap[0]] == 0) {
					break;
				}
				else {
					std::pop_heap(bgnIt, bgnIt + heapLen, cmp);
					-- heapLen;
					-- hashTbl[heap[heapLen]];
					++ cmdCnt;
				}
			}
			std::make_heap(bgnIt, endIt, cmp);
		}
		return n * (rndCnt - 1) + cmdCnt;
	}
};
