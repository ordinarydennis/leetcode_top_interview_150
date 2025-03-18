class Solution {

	void dfs(int index, int n, int k, vector<int>& v)
	{
		if (v.size() == k)
		{
			ret.push_back(v);
			return;
		}

		for (int i = index; i <= n; i++)
		{
			v.push_back(i);
			dfs(i + 1, n, k, v);
			v.pop_back();
		}
	}

	vector<vector<int>> ret;

public:
	vector<vector<int>> combine(int n, int k) {

		vector<int> v;

		dfs(1, n, k, v);

		return ret;
	}
};