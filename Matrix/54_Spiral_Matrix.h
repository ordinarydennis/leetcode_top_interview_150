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



class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int maxX = matrix[0].size() - 1;
		int maxY = matrix.size() - 1;
		int minX = 0;
		int minY = 0;

		vector<int> ret;

		while (ret.size() < matrix.size() * matrix[0].size())
		{
			for (int x = minX; x <= maxX; x++)
			{
				ret.push_back(matrix[minY][x]);
			}

			for (int y = minY + 1; y <= maxY; y++)
			{
				ret.push_back(matrix[y][maxX]);
			}

			if (minY != maxY)
			{
				for (int x = maxX - 1; minX <= x; x--)
				{
					ret.push_back(matrix[maxY][x]);
				}
			}
			if (minX != maxX)
			{
				for (int y = maxY - 1; minY < y; y--)
				{
					ret.push_back(matrix[y][minX]);
				}
			}

			minX++;
			minY++;
			maxX--;
			maxY--;
		}

		return ret;
	}
};



class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int minX = 0;
		int minY = 0;
		int maxX = matrix[0].size() - 1;
		int maxY = matrix.size() - 1;

		vector<int> ret;

		while (ret.size() < matrix[0].size() * matrix.size())
		{
			for (int i = minX; i <= maxX; i++)
			{
				ret.push_back(matrix[minY][i]);
			}

			for (int i = minY + 1; i <= maxY; i++)
			{
				ret.push_back(matrix[i][maxX]);
			}

			if (minY < maxY)
			{
				for (int i = maxX - 1; minX <= i; i--)
				{
					ret.push_back(matrix[maxY][i]);
				}
			}

			if (minX < maxX)
			{
				for (int i = maxY - 1; minY < i; i--)
				{
					ret.push_back(matrix[i][minX]);
				}
			}

			minX++;
			maxX--;
			minY++;
			maxY--;
		}

		return ret;
	}
};

