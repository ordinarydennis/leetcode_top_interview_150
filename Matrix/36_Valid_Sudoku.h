class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		for (int y = 0; y < 9; y++)
		{
			unordered_set<int> st;
			unordered_set<int> st2;
			unordered_set<int> st3;

			for (int x = 0; x < 9; x++)
			{
				if ('.' != board[y][x] && st.count(board[y][x]))
				{
					return false;
				}
				else
				{
					st.emplace(board[y][x]);
				}
				
				if ('.' != board[x][y] && st2.count(board[x][y]))
				{
					return false;
				}
				else
				{
					st2.emplace(board[x][y]);
				}
				
				int x2 = ((y % 3) * 3) + (x % 3);
				int y2 = ((y / 3) * 3) + (x / 3);
				if ('.' != board[y2][x2] && st3.count(board[y2][x2]))
				{
					return false;
				}
				else
				{
					st3.emplace(board[y2][x2]);
				}	
			}
		}

		return true;
	}
};

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int maxY = board.size();
		int maxX = board[0].size();

		for (int y = 0; y < maxY; y++)
		{

			unordered_set<int> set1;
			unordered_set<int> set2;
			unordered_set<int> set3;

			for (int x = 0; x < maxX; x++)
			{
				if ('.' != board[y][x])
				{
					int n = board[y][x] - '0';
					if (set1.count(n))
						return false;
					set1.insert(n);
				}
			
				if ('.' != board[x][y])
				{
					int n = board[x][y] - '0';
					if (set2.count(n))
						return false;
					set2.insert(n);
				}

				int x2 = (y % 3) * 3 + (x % 3);
				int y2 = (y / 3) * 3 + (x / 3);

				if ('.' != board[y2][x2])
				{
					int n = board[y2][x2] - '0';
					if (set3.count(n))
						return false;
					set3.insert(n);
				}	
			}

		}

		return true;
	}
};