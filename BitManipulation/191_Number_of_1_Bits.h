class Solution {
public:
	int hammingWeight(int n) {

		int ret = 0;

		while (n)
		{
			ret += (n % 2);
			n = n / 2;
		}

		return ret;
	}
};