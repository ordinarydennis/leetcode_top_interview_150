class Solution {

	void dfs(int index, vector<int>& candidates, vector<int>& list, int target)
	{
		if (target < 0)
		{
			return;
		}

		if (0 == target)
		{
			ret.push_back(list);
			return;
		}

		for (int i = index; i < candidates.size(); i++)
		{
			list.push_back(candidates[i]);

			dfs(i, candidates, list, target - candidates[i]);

			list.pop_back();
		}
	}


	vector<vector<int>> ret;

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<int> list;

		dfs(0, candidates, list, target);

		return ret;
	}
};