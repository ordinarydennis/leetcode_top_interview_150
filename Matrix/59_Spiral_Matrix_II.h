class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> ret(n, vector<int>(n));

		int i = 1;

		int max = n - 1;

		for (int y = 0; y <= max - y; y++)
		{
			for (int x = y; x <= max - y; x++)
			{
				ret[y][x] = i++;

			}

			for (int y2 = y + 1; y2 < max - y; y2++)
			{
				ret[y2][max - y] = i++;

			}

			for (int x2 = max - y; y < x2; x2--)
			{
				ret[max - y][x2] = i++;

			}

			for (int y3 = max - y; y < y3; y3--)
			{
				ret[y3][y] = i++;
			}
		}

		return ret;
	}
};