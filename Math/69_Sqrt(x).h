class Solution {
public:
	int mySqrt(int x) {

		int ret = 0;

		for (long long i = 0; i <= x; i++)
		{
			if (i * i <= x)
			{
				ret = i;
			}
			else
			{
				break;
			}
		}


		return ret;
	}
};