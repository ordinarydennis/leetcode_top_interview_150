class Solution {
public:
	int singleNumber(vector<int>& nums) {

		unordered_map<int, int> m;

		for (int n : nums)
		{
			if (m.count(n))
			{
				if (1 == m[n])
				{
					m[n]++;
				}
				else
				{
					m.erase(n);
				}
			}
			else
			{
				m[n]++;
			}
		}

		return m.begin()->first;
	}
};



