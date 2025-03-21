class Solution {

	void dfs(string str, int n, int openCount, int closeCount)
	{
		if (n == closeCount)
		{
			ret.push_back(str);
			return;
		}

		if (openCount < n)
			dfs(str + "(", n, openCount + 1, closeCount);
		
		if (closeCount < openCount  && closeCount < n)
			dfs(str + ")", n, openCount, closeCount + 1);
	}

	vector<string> ret;

public:
	vector<string> generateParenthesis(int n) {

		string str;

		dfs(str, n, 0, 0);

		return ret;
	}
};