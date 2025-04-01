class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {

		vector<int> ret;

		int c = 1;

		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			ret.push_back((c + *it) % 10);
			c = (c + *it) / 10;
		}

		if (0 < c)
			ret.push_back(c);

		reverse(ret.begin(), ret.end());

		return ret;
	}
};
