class Solution {

	bool dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visit, vector<vector<int>>& out)
	{
		if (x < 0 || maxX <= x || y < 0 || maxY <= y)
			return false;

		if (visit[y][x])
			return true;

		if ('X' == board[y][x])
			return true;

		visit[y][x] = true;

		if ('O' == board[y][x])
		{
			out.push_back(vector<int> {x, y});

			return
				dfs(x + 1, y, board, visit, out) &&
				dfs(x - 1, y, board, visit, out) &&
				dfs(x, y + 1, board, visit, out) &&
				dfs(x, y - 1, board, visit, out);
		}

		return false;
	}

	int maxX = 0;
	int maxY = 0;

public:
	void solve(vector<vector<char>>& board) {

		maxX = board[0].size();
		maxY = board.size();

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				if ('X' == board[y][x])
					continue;

				vector<vector<bool>> visit(maxY, vector<bool>(maxX));

				vector<vector<int>> out;

				if (false == dfs(x, y, board, visit, out))
					continue;

				for(int a = 0; a < out.size(); a++)
				{
					board[out[a][1]][out[a][0]] = 'X';
				}
			}
		}
	}
};