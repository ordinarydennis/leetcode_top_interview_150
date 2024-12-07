//fail tle
class Solution {
public:
	int maxProfit(vector<int>& prices) {


		int ret = INT_MIN;

		for (int a = 0; a < prices.size() - 1; a++)
		{
			int n = INT_MIN;

			for (int b = a + 1; b < prices.size(); b++)
			{
				n = std::max(n, prices[b] - prices[a]);
			}

			ret = max(ret, n);
		}

		return 0 < ret ? ret : 0;
	}
};

//accepted
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int max = prices[prices.size() - 1], ret = 0;

		for (int i = prices.size() - 2; 0 <= i; i--)
		{
			ret = std::max(ret, max - prices[i]);
			max = std::max(max, prices[i]);
		}

		return ret;
	}
};