class Solution {

	bool dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visit)
	{
		if (visit[y][x])
			return false;

		visit[y][x] = true;

		static vector<vector<int>> dir = {
			{ -1, 0  },
			{ 0, -1 },
			{ 1, 0  },
			{ 0, 1  }
		};

		bool isExist = '1' == grid[y][x];

		if (!isExist)
		{
			return false;
		}

		for (auto d : dir)
		{
			int dy = d[0] + y;
			int dx = d[1] + x;

			if (dy < 0 || dx < 0)
			{
				continue;
			}

			if (yMax <= dy || xMax <= dx)
			{
				continue;
			}

			if ('0' == grid[dy][dx])
			{
				continue;
			}
		
			dfs(dx, dy, grid, visit);
		}

		return isExist;
	}

	int xMax = 0;
	int yMax = 0;
	

public:
	int numIslands(vector<vector<char>>& grid) {

		xMax = grid[0].size();
		yMax = grid.size();

		int ret = 0;

		vector<vector<bool>> visit(yMax, vector<bool>(xMax));

		for (int y = 0; y < yMax; y++)
		{
			for (int x = 0; x < xMax; x++)
			{
				if (dfs(x, y, grid, visit))
				{
					ret++;
				}
			}
		}

		return ret;
	}
};