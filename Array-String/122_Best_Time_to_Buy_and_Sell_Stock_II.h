class Solution {

	void dfs(bool isSell, int index, int pre, int sum, vector<int>& prices)
	{
		if (prices.size() <= index)
		{
			ret = max(ret, sum);
			return;
		}

		for (int i = index; i < prices.size(); i++)
		{
			if (isSell)
			{
				if (prices[i] <= pre)
				{
					continue;
				}

				int add = prices[i] - pre;

				dfs(false, i, prices[i], sum + add, prices);
			}
			else
			{
				dfs(true, i + 1, prices[i], sum, prices);
			}
		}
	}

	int ret = 0;

public:
	int maxProfit(vector<int>& prices) {

		dfs(false, 0, 0, 0, prices);

		return ret;
	}
};


class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int ret = 0;

		for (int i = 0; i < prices.size() -1;)
		{
			while (i < prices.size() - 1 && prices[i + 1] < prices[i])
			{
				i++;
			}

			int buy = prices[i];

			while (i < prices.size() - 1 && prices[i] < prices[i + 1])
			{
				i++;
			}

			ret += prices[i] - buy;

			i++;
		}

		return ret;

	}
};
