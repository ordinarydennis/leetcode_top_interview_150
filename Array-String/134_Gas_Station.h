
// time limit exceed
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int max = gas.size();

		for (int i = 0; i < max; i++)
		{
			int remain = 0;

			bool s = true;

			for (int a = i; a < i + max; a++)
			{
				int curIndex = a % max;

				remain += gas[curIndex];

				if (remain < cost[curIndex])
				{
					s = false;
					break;
				}

				remain -= cost[curIndex];
			}
			if (s)
			{
				return i;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int total = 0;
		int cur = 0;
		int ret = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			total += gas[i] - cost[i];
			cur += gas[i] - cost[i];

			if (cur < 0)
			{
				cur = 0;
				ret = i + 1;
			}
		}

		return 0 <= total ? ret : -1;
	}
};