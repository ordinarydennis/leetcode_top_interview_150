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

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();

		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				int temp = matrix[n - 1 - j][i];

				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];

				matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];

				matrix[j][n - 1 - i] = matrix[i][j];

				matrix[i][j] = temp;
			}
		}
	}
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		transpose(matrix);
		reflect(matrix);
	}

private:
	void transpose(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[j][i], matrix[i][j]);
			}
		}
	}
	void reflect(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
	}
};
