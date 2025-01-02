class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {

		int maxY = board.size();
		int maxX = board[0].size();

		vector<vector<int>> dirs = {
			{  0, 1 },
			{  1, 1 },
			{  1, 0 },
			{  1, -1 },
			{  0, -1 },
			{ -1, -1 },
			{ -1, 0 },
			{ -1, 1 },
		};

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				int count = 0;

				for (const auto& d : dirs)
				{
					int y2 = d[0];
					int x2 = d[1];

					if (
						0 <= x + x2 && x + x2 < maxX && 
						0 <= y + y2 && y + y2 < maxY
						)
					{

						if (1 == board[y + y2][x + x2] || 2 == board[y + y2][x + x2])
						{
							count++;
						}
					}
				}

				if (1 == board[y][x])
				{
					//Any live cell with fewer than two live neighbors dies as if caused by under - population.
					if (count < 2)
					{
						board[y][x] = 2;
					}
					else if (count == 2 || count == 3)
					{
						//Any live cell with two or three live neighbors lives on to the next generation.
						//
					}
					else if (3 < count)
					{
						//Any live cell with more than three live neighbors dies, as if by over - population.
						board[y][x] = 2;
					}
				}
				else
				{
					//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
					if (3 == count)
					{
						board[y][x] = 3;
					}
				}
			}
		}

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				if (2 == board[y][x])
				{
					board[y][x] = 0;
				}
				else if (3 == board[y][x])
				{
					board[y][x] = 1;
				}
				
			}
		}
	}
};

