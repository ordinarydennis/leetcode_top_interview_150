//fail
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int minX = 0;
		int minY = 0;

		int maxX = matrix[0].size();
		int maxY = matrix.size();

		vector<int> ret;

		while (minX < maxX || minY < maxY)
		{
			for (int x = minX; x < maxX; x++)
			{
				ret.push_back(matrix[minY][x]);
			}

			for (int y = minY; y < maxY; y++)
			{
				ret.push_back(matrix[y][maxX - 2]);
			}

			for (int x = maxX - 1; minX < x; x--)
			{
				ret.push_back(matrix[maxY - 2][x]);
			}

			for (int y = maxY - 1; minY < y; y--)
			{
				ret.push_back(matrix[y][minX]);
			}

			minX++;
			minY++;
			maxX--;
			maxY--;
		}

 
		return ret;
	}
};
