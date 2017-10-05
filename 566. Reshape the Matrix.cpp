class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int height = nums.size(), width = nums[0].size();
		if (height * width != r * c) return nums;
		vector<vector<int>> res(r, vector<int>(c));
		int row = 0, column = 0;
		for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			res[row][column++] = nums[y][x];
            if (column == c) column = 0, row++;
		}
		return res;
	}
};
