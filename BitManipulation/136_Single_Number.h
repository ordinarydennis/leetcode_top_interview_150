class Solution {
public:
	int singleNumber(vector<int>& nums) {

		unordered_set<int> s;

		for (int n : nums)
		{
			if (s.count(n))
				s.erase(n);
			else
				s.insert(n);
		}

		if (!s.empty())
			return *s.begin();

		return 0;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int a = 0;
		
		for (int n : nums)
		{
			if (a & 1 << n)
			{
				a ^= 1 << n;
			}
			else
			{
				a |= 1 << n;
			}
		}

		int ret = 0;

		while (a)
		{
			if (a & 1)
			{
				return ret;
			}
			
			ret++;
			a = a >> 1;
		}

		return 0;
	}
};

