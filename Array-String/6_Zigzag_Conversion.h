class Solution {
public:
	string convert(string s, int numRows) {

		if (1 == numRows)
		{
			return s;
		}

		vector<vector<char>> v(numRows, vector<char>(s.size(), ' '));

		int r = 0;
		int c = 0;

		int dir = 1;

		for (int i = 0; i < s.size(); i++)
		{
			v[r][c] = s[i];

			r += (1 * dir);

			if (r == numRows)
			{
				dir *= -1;
				r -= 2;
			}

			if (-1 == dir)
			{
				c++;
			}

			if (r < 0)
			{
				dir *= -1;
				r += 2;
			}
		}

		string ret;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				if (' ' != v[i][j])
				{
					ret += v[i][j];
				}

			}
		}

		return ret;
	}
};
 