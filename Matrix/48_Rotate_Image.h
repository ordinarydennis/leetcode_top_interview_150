//fail
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int maxX = matrix[0].size() - 1;
		int maxY = matrix.size();


		int x = 0, y = 0;

		for (int i = 0; i < maxX; i++)
		{
			int temp = matrix[y][maxX];
			matrix[y][maxX] = matrix[y][x];

			int temp2 = matrix[maxY][maxX];
			matrix[maxY][maxX] = temp;

			int temp3 = matrix[maxY][x];
			matrix[maxY][x] = temp2;

			matrix[y][x] = temp3;

			x++;
			y++;
		}

	}
};