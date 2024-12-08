class Solution {

	bool dfs(int index, vector<int>& nums)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (nums.size() <= index)
		{
			return false;
		}

		if (nums.size() - 1 == index)
		{
			return true;
		}

		int n = nums[index];

		for (int i = index + n;  index < i; i--)
		{
			if (dfs(i, nums))
			{
				memo[index] = true;
				return true;
			}
		}

		memo[index] = false;
		return false;
	}

	std::unordered_map<int, bool> memo;


public:
	bool canJump(vector<int>& nums) {

		return dfs(0, nums);

	}
};


class Solution {

public:
	bool canJump(vector<int>& nums) {

		if (1 == nums.size())
		{
			return true;
		}

		std::vector<bool> dp(nums.size());

		int last = nums.size() - 1;

		for (int i = last - 1; 0 <= i; i--)
		{
			if (last <= i + nums[i])
			{
				dp[i] = true;
				continue;
			}

			for (int a = i + 1; a <= i + nums[i]; a++)
			{
				if (dp[a])
				{
					dp[i] = true;
				}
			}
		}

		return dp[0];
	}
};

class Solution {

public:
	bool canJump(vector<int>& nums) {

		int last = nums.size() - 1;

		for (int i = last; 0 <= i; i--)
		{
			if (last <= i + nums[i])
			{
				last = i;
			}
		}

		return 0 == last;
	}
};