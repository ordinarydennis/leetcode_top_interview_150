class Solution {

	int dfs(int index, int count, vector<int>& nums)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (nums.size() - 1 <= index)
		{
			return 0;
		}

		int ret = 1000000;

		for (int i = index + 1; i <= index + nums[index]; i++)
		{
			int r = dfs(i, count + 1, nums) + 1;

			ret = std::min(ret, r);
		}

		return memo[index] = ret;
	}

	std::unordered_map<int, int> memo;


public:
	int jump(vector<int>& nums) {

		return dfs(0, 0, nums);

	}
};