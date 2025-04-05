class Solution {


	int dfs(int c, int n)
	{
		if (m.count(c))
			return m[c];

		if (c == n)
			return 1;

		if (n < c)
			return 0;

		return m[c] = dfs(c + 1, n) + dfs(c + 2, n);
	}


	unordered_map<int, int> m;

public:
	int climbStairs(int n) {

		return dfs(0, n);

	}
};
