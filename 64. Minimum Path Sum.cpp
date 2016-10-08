class Solution {
private:
	// grid info
	int m, n;
	vector<vector<int>>* pGrid;
	// a global table
	typedef bool *ArrayLine;
	ArrayLine *computed;
	typedef int *AnoLine;
	AnoLine *minSumOf;

	void DP(int x, int y) {// only backtracking from the right bottom corner is valid
		// the base case
		if (x == n - 1 && y == m - 1) {
			this->computed[y][x] = true;
			this->minSumOf[y][x] = (*pGrid)[y][x];
			return;
		}

		// enumerate possible next steps
		int subsequentSum = INT_MAX;
		if (x + 1 < this->n) {
			if (!this->computed[y][x+1]) DP(x+1, y);
		    int result = minSumOf[y][x + 1];
			if (result < subsequentSum) subsequentSum = result;
		}
		if (y + 1 < this->m) {
			if (!this->computed[y+1][x]) DP(x, y+1);
			int result = minSumOf[y + 1][x];
			if (result < subsequentSum) subsequentSum = result;
		}
		
		// return
		this->computed[y][x] = true;
		this->minSumOf[y][x] = subsequentSum + (*pGrid)[y][x];
		return;
	}
public:
	int minPathSum(vector<vector<int>>& grid) {
		// the response
		int res = 0;
		this->m = grid.size();
		if (this->m == 0) return res;
		this->n = grid[0].size();
		this->pGrid = &grid;

		// dynamic programming
		this->computed = new ArrayLine[m];
		this->minSumOf = new AnoLine[m];
		for (int i = 0; i < m; i++) {
			this->computed[i] = new bool[n];
			this->minSumOf[i] = new int[n];
			memset(this->computed[i], false, sizeof(bool)*n);
		}
        
        DP(0, 0);
		res = this->minSumOf[0][0];

		/*for (int i = 0; i < m; i++) {
			delete[] this->computed[i];
			delete[] this->minSumOf[i];
		}
		delete[] this->computed;
		delete[] this->minSumOf;*/

		// return
		return res;
	}
};
