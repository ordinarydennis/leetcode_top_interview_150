class Solution {
public:
	double myPow(double x, int n) {

		double ret = 1;

		if (1 == x)
		{
			return 1;
		}

		long long z = n;
		if (z < 0)
		{
			z *= -1;
		}

		for (int i = 0; i < z; i++)
		{
			ret *= x;
		}

		if (n < 0)
		{
			ret = 1 / ret;
		}

		return ret;

	}
};