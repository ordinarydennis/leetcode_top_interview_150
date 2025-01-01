class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		int maxX = matrix[0].size();
		int maxY = matrix.size();

		vector<vector<int>> posList;

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				if (0 != matrix[y][x])
					continue;

				posList.emplace_back(std::move(vector<int> { y, x }));
			}
		}

		for (const auto& pos : posList)
		{
			int y2 = pos[0]; //y
			int x2 = pos[1]; //x

			for (int x = 0; x < maxX; x++)
			{
				matrix[y2][x] = 0;
			}

			for (int y = 0; y < maxY; y++)
			{
				matrix[y][x2] = 0;
			}
		}
	}
};


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool isCol = false;
		int R = matrix.size();
		int C = matrix[0].size();
		for (int i = 0; i < R; i++) {
			if (matrix[i][0] == 0) {
				isCol = true;
			}
			for (int j = 1; j < C; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < R; i++) {
			for (int j = 1; j < C; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (matrix[0][0] == 0) {
			for (int j = 0; j < C; j++) {
				matrix[0][j] = 0;
			}
		}

		if (isCol) {
			for (int i = 0; i < R; i++) {
				matrix[i][0] = 0;
			}
		}
	}
};



class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		int maxY = matrix.size();
		int maxX = matrix[0].size();

		bool isStartZero = 0 == matrix[0][0];

		bool isZeroC = false;
		for (int x = 0; x < maxX; x++)
		{
			isZeroC = 0 == matrix[0][x];
			if (isZeroC)
			{
				break;
			}
		}

		bool isZeroR = false;
		for (int y = 0; y < maxY; y++)
		{
			isZeroR = 0 == matrix[y][0];
			if (isZeroR)
			{
				break;
			}
		}

		for (int y = 1; y < maxY; y++)
		{
			for (int x = 1; x < maxX; x++)
			{
				if (0 == matrix[y][x])
				{
					matrix[0][x] = 0;
					matrix[y][0] = 0;
				}
			}
		}

		for (int y = 1; y < maxY; y++)
		{
			for (int x = 1; x < maxX; x++)
			{
				if (0 == matrix[0][x] || 0 == matrix[y][0])
				{
					matrix[y][x] = 0;
				}
			}
		}

		if (isStartZero)
		{
			for (int x = 0; x < maxX; x++)
				matrix[0][x] = 0;

			for(int y = 0; y < maxY; y++)
				matrix[y][0] = 0;
		}

		if (isZeroC)
		{
			for (int x = 0; x < maxX; x++)
				matrix[0][x] = 0;
		}

		if (isZeroR)
		{
			for (int y = 0; y < maxY; y++)
				matrix[y][0] = 0;
		}
	}
};

//fail
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		int maxY = matrix.size();
		int maxX = matrix[0].size();

		bool isCol = false;

		for (int y = 0; y < maxY; y++)
		{
			if (matrix[y][0])
			{
				isCol = true;
			}

			for (int x = 0; x < maxX; x++)
			{
				if (0 == matrix[y][x])
				{
					matrix[0][x] = 0;
					matrix[y][0] = 0;
				}
			}
		}

		for (int y = 1; y < maxY; y++)
		{
			for (int x = 1; x < maxX; x++)
			{
				if (0 == matrix[0][x] || 0 == matrix[y][0])
				{
					matrix[y][x] = 0;
				}
			}
		}

		if (isCol)
		{
			for (int y = 0; y < maxY; y++)
			{
				matrix[y][0] = 0;
			}
		}
	}
};